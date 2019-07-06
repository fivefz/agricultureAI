# -*- coding: utf-8 -*-
"""
Created on Sat Jul  6 21:15:50 2019

@author: xiaoyifu
"""

import argparse
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from augmentation import FarmDataset
 
from segnet import segnet_bn_relu as Unet
 
import time
 
from PIL import Image 

prefix='E:/match/tianchi_agriculture/' 

def train(args, model, device, train_loader, optimizer, epoch):
    model.train()
    for batch_idx, (data, target) in enumerate(train_loader):
        data, target = data.to(device), target.to(device)
        #print(target.shape)
        optimizer.zero_grad()
        output = model(data)
        #print('output size',output.size(),output)
 
        output = F.log_softmax(output, dim=1)
        loss=nn.NLLLoss2d(weight=torch.Tensor([0.1,0.5,0.5,0.2]).to('cuda'))(output,target)
        loss.backward()
        
        optimizer.step()
 
        #time.sleep(0.6)#make gpu sleep
        if batch_idx % args.log_interval == 0:
            print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                epoch, batch_idx * len(data), len(train_loader.dataset),
                100. * batch_idx / len(train_loader), loss.item()))
    if epoch%2==0:
        imgd=output.detach()[0,:,:,:].cpu()
        img=torch.argmax(imgd,0).byte().numpy()
        imgx=Image.fromarray(img).convert('L')
        imgxx=Image.fromarray(target.detach()[0,:,:].cpu().byte().numpy()*255).convert('L')
        imgx.save(prefix+"data/tmp/predict{}.bmp".format(epoch))
        imgxx.save(prefix+'data/tmp/real{}.bmp'.format(epoch))
 
def test(args, model, device, testdataset,issave=False):
    model.eval()
    test_loss = 0
    correct = 0
    evalid=[i+7 for i in range(0,2100,15)]
    maxbatch=len(evalid)
    with torch.no_grad():
        for idx in evalid:
            data, target=testdataset[idx]
            data, target = data.unsqueeze(0).to(device), target.unsqueeze(0).to(device)
            #print(target.shape)
            target=target[:,:1472,:1472]
            output = model(data[:,:,:1472,:1472])
            output = F.log_softmax(output, dim=1)
            loss=nn.NLLLoss2d().to('cuda')(output,target)
            test_loss+=loss
             
            r=torch.argmax(output[0],0).byte()
  
            tg=target.byte().squeeze(0)
            tmp=0
            count=0
            for i in range(1,4):
                mp=r==i
                tr=tg==i
                tp=mp*tr==1
                t=(mp+tr-tp).sum().item()
                if t==0:
                    continue
                else:
                    tmp+=tp.sum().item()/t
                    count+=1
            if count>0:
                correct+=tmp/count
            
             
            if issave:
                Image.fromarray(r.cpu().numpy()).save('predict.png')
                Image.fromarray(tg.cpu().numpy()).save('target.png')
                input()
                 
    print('Test Loss is {:.6f}, mean precision is: {:.4f}%'.format(test_loss/maxbatch,correct))
 
 
def main():
    # Training settings
    parser = argparse.ArgumentParser(description='Scratch segmentation Example')
    parser.add_argument('--batch-size', type=int, default=8, metavar='N',
                        help='input batch size for training (default: 64)')
    parser.add_argument('--test-batch-size', type=int, default=8, metavar='N',
                        help='input batch size for testing (default: 1000)')
    parser.add_argument('--epochs', type=int, default=30, metavar='N',
                        help='number of epochs to train (default: 10)')
    parser.add_argument('--lr', type=float, default=0.001, metavar='LR',
                        help='learning rate (default: 0.01)')
    parser.add_argument('--momentum', type=float, default=0.5, metavar='M',
                        help='SGD momentum (default: 0.5)')
    parser.add_argument('--no-cuda', action='store_true', default=False,
                        help='disables CUDA training')
    parser.add_argument('--seed', type=int, default=1, metavar='S',
                        help='random seed (default: 1)')
    parser.add_argument('--log-interval', type=int, default=10, metavar='N',
                        help='how many batches to wait before logging training status')
    args = parser.parse_args()
    use_cuda = not args.no_cuda and torch.cuda.is_available()
 
    torch.manual_seed(args.seed)
 
    device = torch.device("cuda" if use_cuda else "cpu")
    print('my device is :',device)
 
    kwargs = {'num_workers': 0, 'pin_memory': True} if use_cuda else {}
    train_loader = torch.utils.data.DataLoader(     FarmDataset(istrain=True),batch_size=args.batch_size, shuffle=True,drop_last=True, **kwargs)
     
    startepoch=0
    model =torch.load(prefix+'data/model{}'.format(startepoch))  if startepoch else Unet(3,4).to(device) 
    args.epochs=50
    optimizer = optim.SGD(model.parameters(), lr=args.lr, momentum=args.momentum)
 
    for epoch in range(startepoch, args.epochs + 1):
        train(args, model, device, train_loader, optimizer, epoch)
        if epoch %3==0:
            print(epoch)
            test(args, model, device, FarmDataset(istrain=True,isaug=False),issave=False)
            torch.save(model,prefix+'data/model{}'.format(epoch))
     
if __name__ == '__main__':
    main()