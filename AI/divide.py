# -*- coding: utf-8 -*-
"""
Created on Thu Jul  4 21:52:38 2019

@author: xiaoyifu
"""
from PIL import Image
import numpy as np

def read_image(fileName):
    Image.MAX_IMAGE_PIXELS = 100000000000 #突破限定
    img = Image.open(fileName)   # 注意修改img路径
    #print(img.mode)
    img = np.asarray(img) #与array的区别在于是否复制出新的ndarray
    #plt.imshow(img)
    #pylab.show()
    
    return img

def divideAndSave(img,x,y,prefix): #注意右边界和下边界，考虑对原图进行0填充
    if img.shape[0]%x!=0:
        row=img.shape[0]//x+1 #行方向需要的块数
    else:
        row=img.shape[0]//x
    if img.shape[1]%y!=0:   #列方向需要的块数
        col=img.shape[1]//y+1
    else:
        col=img.shape[1]//y
    tol=np.ones((row,col,x,y))
    for m in range(row):
        for n in range(col):
            for p in range(x):
                for q in range(y):
                    if x*m+p<img.shape[0] and y*n+q<img.shape[1]: #小心数组越界
                       tol[m][n][p][q]=img[x*m+p][y*n+q]
            image=tol[m][n]           
            saveImgFromArray(image,prefix,str(m)+'_'+str(n))
    #return tol

def saveImgFromArray(array,prefix,middle):
    #print(array.shape)
    #for i in range(array.shape[0]):
    #    for j in range(array.shape[1]):
    #        im=Image.fromarray(array)
    #        im.save(prefix+str(i)+'_'+str(j)+'.jpeg')
    im=Image.fromarray(array)
    if im.mode == "F":
        im = im.convert('RGB')
    im.save(prefix+middle+'.jpeg')
    
prefix='E:/match/tianchi_agriculture/'
anno_map =prefix+'initial/jingwei_round1_train_20190619/image_1_label.png'   # 注意修改label路径
img=read_image(anno_map)
prefixPhoto='photo/'
divideAndSave(img,500,500,prefix+prefixPhoto)
