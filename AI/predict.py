# -*- coding: utf-8 -*-
"""
Created on Mon Jul  8 09:43:49 2019

@author: xiaoyifu
"""

from augmentation import FarmDataset
import torch as tc
from osgeo import gdal
#from torchvision import transforms
import png
import numpy as np
import os
#from PIL import Image
import tornado.web
from tornado.escape import json_encode
import traceback
#from StringIO import StringIO
#import requests
import urllib
#import urllib.request
import json
from requests_toolbelt import MultipartEncoder
import requests

use_cuda=True
device = tc.device("cuda" if use_cuda else "cpu")
prefix='E:/match/tianchi_agriculture/'
model=tc.load(prefix+'data/model/model30')  #torch.save(model,'./tmp/model{}'.format(epoch))
model=model.to(device)
model.eval()

def test():
    ds=FarmDataset(istrain=False)
    print("start predict.....")
    predict(ds[0],'image_3_predict.png')
    print("start predict 2 .....")
    predict(ds[1],'image_4_predict.png')

class MyHandler(tornado.web.RequestHandler):
    def post(self):
        result = {}
        image_url = self.get_argument("image_url", default="")
        pid = self.get_argument("id", default="")
        return_url=self.get_argument("return_url",default="")
        print(image_url)
        result["id"]=pid
        if not image_url:
            result["msg"] = "no image url"
        else:
            result["msg"] = "开始分析!!"
            self.process(image_url,return_url)
        self.write(json_encode(result))
     
    def doPost(self,server_url, params):
        #data = urllib.urlencode(params)
        #fp=open(params,'rb')
        print('开始上传图片')
        file_payload = {'file': (params, open(params, 'rb'), "image/png")}
        m = MultipartEncoder(file_payload)
        print(type(m))
        print(m)
        requests.post(server_url,data=m)
        #data = []
        #data.append(fp.read())
        #request = urllib.request.Request(server_url, data)
        #return json.loads(urllib.request.urlopen(request, timeout=10).read())

    def process(self, image_url,return_url):
        try:
            filename=os.path.basename(image_url)
            filename=prefix+'/AI/test/'+filename
            urllib.request.urlretrieve(image_url,filename=filename)#已经下载到指定目录
            ds=FarmDataset(istrain=False)
            print("start predict.....")
            predict(ds[0],'image_predict.png')
            self.doPost(return_url,prefix+'/data/temp/image_predict.png')
            #response = requests.get(image_url)
            #if response.status_code == requests.codes.ok:
                #with open(prefix+'AI/test','wb') as f:  #打开写入到path路径里-二进制文件，返回的句柄名为f
                    #f.write(response.content)
                # TODO 根据obj进行相应的操作
             #   return "ok"
            #else:
              #  return "get image failed."
        except Exception as e:
            print(traceback.format_exc())
            return str(e)

class Server(object):
    def __init__(self, port):
        self.port = port

    def process(self):
        app = tornado.web.Application([(r"/?", MyHandler)], )
        app.listen(self.port)
        try:           
            tornado.ioloop.IOLoop.current().start()
        except Exception as e:
            self.process()

def createres(d,outputname):
    #创建一个和ds大小相同的灰度图像BMP
    driver = gdal.GetDriverByName("BMP")
    #driver=ds.GetDriver()
    od=driver.Create(prefix+'data/temp/'+outputname,d.RasterXSize,d.RasterYSize,1)
    return od
 
def createpng(height,width,data,outputname):
    w=png.Writer(width,height,bitdepth=2,greyscale=True)
    of=open(prefix+'data/temp/'+outputname,'wb')
    w.write_array(of,data.flat)
    of.close()
    print('已在本地建立结果图片')

def predict(d,outputname='tmp.bmp'):
    wx=d.RasterXSize   #width
    wy=d.RasterYSize   #height
    print(wx,wy)
    od=data=np.zeros((wy,wx),np.uint8)
    #od=createres(d,outputname=outputname)
    #ob=od.GetRasterBand(1) #得到第一个channnel
    blocksize=1024
    step=512
    for cy in range(step,wy-blocksize,step):
        for cx in range(step,wx-blocksize,step):
            img=d.ReadAsArray(cx-step,cy-step,blocksize,blocksize)[0:3,:,:] #channel*h*w
            if (img.sum()==0): continue
            x=tc.from_numpy(img/255.0).float()
            #print(x.shape)
            x=x.unsqueeze(0).to(device)
            r=model.forward(x)
            r=tc.argmax(r.cpu()[0],0).byte().numpy()  #512*512
            #ob.WriteArray(r,cx,cy)
            od[cy-step//2:cy+step//2,cx-step//2:cx+step//2]=r[256:step+256,256:step+256]
            print(cy,cx)
    #del od
    createpng(wy,wx,od,outputname)

if __name__ == '__main__':    
    server_port = "9000"
    server = Server(server_port)
    print("begin server")
    server.process()
    
