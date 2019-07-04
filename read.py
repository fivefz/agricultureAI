# -*- coding: utf-8 -*-
"""
Created on Thu Jul  4 10:26:10 2019

@author: xiaoyifu
"""

#import os
#import cv2
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import pylab #pylab是matplotlib中的模块

def read_image(fileName):
    Image.MAX_IMAGE_PIXELS = 100000000000 #突破限定
    img = Image.open(fileName)   # 注意修改img路径
    #print(img.mode)
    img = np.asarray(img) #与array的区别在于是否复制出新的ndarray
    plt.imshow(img)
    pylab.show()
    
    return img

def sign(img):
    tobacco=[]
    corn=[]
    yiRenMi=[]
    print(img.shape[0])
    print(img.shape[1])
    for x in range(img.shape[0]):
        for y in range(img.shape[1]):
            if img[x][y]==1: #说明这是烤烟
                tobacco.append((x,y))
                print('k')
            elif img[x][y]==2: #玉米
                corn.append((x,y))
                print('y')
            elif img[x][y]==3: #薏仁米
                yiRenMi.append((x,y))
                print('r')
            print('h')
    return tobacco,corn,yiRenMi
                
def printFile(content,fileName):
    fh = open(fileName, 'a+', encoding='utf-8')
    for i in range(len(content)):
        fh.write(str(content[i])+'\n')
    fh.close()

prefix='E:/match/tianchi_agriculture/'
#address1='save/test1.txt'
#address2='save/test2.txt'
#address3='save/test3.txt'
#img1=prefix+'jingwei_round1_train_20190619/image_1.png'
#read_image(img1)

#anno_map =prefix+'initial/jingwei_round1_train_20190619/image_1_label.png'   # 注意修改label路径
address=prefix+'photo/1_1.jpeg'
img=read_image(address)
#tobacco,corn,yiRenMi=sign(img)
#printFile(tobacco,prefix+address1)
#printFile(corn,prefix+address2)
#printFile(yiRenMi,prefix+address3)

#saveImgFromArray(array,prefix+prefixPhoto)