# -*- coding: utf-8 -*-
"""
Created on Sat Jul  6 13:14:04 2019

@author: xiaoyifu
"""

from osgeo import gdal
from PIL import Image
#import os

prefix='E:/match/tianchi_agriculture/'
anno_map =prefix+'initial/jingwei_round1_train_20190619/image_1_label.png'   # 注意修改label路径
map=prefix+'initial/jingwei_round1_train_20190619/image_1.png'
dslb=gdal.Open(anno_map)
ds=gdal.Open(map)
wx=ds.RasterXSize
wy=ds.RasterYSize
stx=0
sty=0
step=900
outsize=1500
nullthresh=outsize*outsize*0.7
cx=0
cy=0
while cy+outsize<wy:
    cx=0
    while cx+outsize<wx:
        img=ds.ReadAsArray(cx,cy,outsize,outsize)
        #transpose()函数的(0, 1, 2)对应着(z, y, x)轴
        #这里把它换成了（y，x，z）
        img2=img[:3,:,:].transpose(1,2,0)
        if (img2[:,:,0]==0).sum()>nullthresh:
            cx+=step
            print('kongbai...',cx,cy)
            continue

        img2=Image.fromarray(img2,'RGB')
        img2.save(prefix+'data/initial/'+'image1_{}_{}.bmp'.format(cx,cy))
#deal with label
        img=dslb.ReadAsArray(cx,cy,outsize,outsize)
        img=Image.fromarray(img).convert('L')
        img.save(prefix+'/data/label/'+'image1_{}_{}.bmp'.format(cx,cy))

        cx+=step
    cy+=step