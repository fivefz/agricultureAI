# -*- coding: utf-8 -*-
"""
Created on Tue Jul  9 15:13:53 2019

@author: xiaoyifu
"""

import torch
import CropModels
import CropDataset
import os
from PIL import Image
import utils

NB_CLASS=61
prefix='E:/match/tianchi_agriculture/AI/identify/data/test/'

def getmodel():
    print('[+] loading model... ', end='', flush=True)
    #model=CropModels.resnet50_finetune(NB_CLASS)
    model=CropModels.ResNetFinetune(NB_CLASS)
    #model.cuda()  
    print('Done')
    return model

model=getmodel()
path=os.path.abspath('AI/identify/feature/Resnet50/test_all_prediction.pth')
model.load_state_dict(torch.load(path))
#print(model)
img=Image.open(prefix+'00bcc8a469696ad21157c9e1872cbec5.jpg').convert('RGB')
transform=CropDataset.preprocess(CropDataset.normalize_05,224)
img=transform(img)
#print(type(model))
#print(model)
#print(model.__dict__.items() )
result =model.forward(img.cuda())
print(result)