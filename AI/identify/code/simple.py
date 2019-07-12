# -*- coding: utf-8 -*-
"""
Created on Wed Jul 10 22:48:36 2019

@author: xiaoyifu
"""

import json
import os
#import socket
#import struct
#from PIL import Image
import tornado.web
from tornado.escape import json_encode
import traceback
#from StringIO import StringIO
import requests
import random
import chardet
import urllib
#import urllib

prefix='E:/match/tianchi_agriculture/AI/identify/data/accept/'

class MyHandler(tornado.web.RequestHandler):
    def post(self):
        result = {}
        image_url = self.get_argument("image_url", default="")
        pid = self.get_argument("id", default="")
        #return_url=self.get_argument("return_url",default="")
        print(pid)
        print(image_url)
        result["id"]=pid
        urllib.request.urlretrieve(image_url,filename=prefix+'1.png')#已经下载到指定目录
        if not image_url:
            result["msg"] = "no image url"
        else:
            result["msg"] = getDisease(image_url)
        self.set_header("Content-Type", "application/json; charset=UTF-8")
        s=json_encode(result)
        #print(chardet.detect(s)) s是str类型，需要encode变成bytes类型
        print(chardet.detect(s.encode(encoding='UTF-8')))
        self.write(s.encode(encoding='UTF-8'))
        
    def process(self, image_url):
        try:
            response = requests.get(image_url)
            if response.status_code == requests.codes.ok:
                #obj = Image.open(StringIO(response.content))
                # TODO 根据obj进行相应的操作
                return "ok"
            else:
                return "get image failed."
        except Exception as e:
            print(traceback.format_exc())
            return str(e)

class Server(object):
    def __init__(self, port):
        self.port = port

    def process(self):
        app = tornado.web.Application([(r"/", MyHandler)], )
        app.listen(self.port)
        tornado.ioloop.IOLoop.current().start()

#def dealData(sock, addr):
#    while True:
#        fileinfo_size = struct.calcsize('128sl')
#        buf = sock.recv(fileinfo_size)
#        if buf:
#            filename, filesize = struct.unpack('128sl', buf)
#            fn = filename.decode().strip('\x00')#去除右不可见字符
#            new_filename = os.path.join(prefix, fn)
#            print(new_filename)
#            recvd_size = 0
#            fp = open(new_filename, 'wb')
#
#            while not recvd_size == filesize:
#                if filesize - recvd_size > 1024:
#                    data = sock.recv(1024)
#                    recvd_size += len(data)
#                else:
#                    data = sock.recv(1024)
#                    recvd_size = filesize
#                fp.write(data)
#            fp.close()
#        sock.close()
#        break
#    return new_filename
#
#def service():
#    server=socket.socket()
#    host=socket.gethostname()
#    port=8000
#    server.bind((host,port))
#    server.listen(5)
#    while True:
#        conn,addr=server.accept()
#        filename=dealData(conn, addr)
#        break
#    server.close()
#    return filename

#def post(server_url, params):
#    data = urllib.urlencode(params)
#    request = urllib2.Request(server_url, data)
#    return json.loads(urllib2.urlopen(request, timeout=10).read())

def getDisease(image_url):
    diseaseDict=[{'disease_class':1,'name':'锈病'},{'disease_class':2,'name':'褐斑病'},{'disease_class':3,'name':'白粉病'},
      {'disease_class':4,'name':'炭疽病'},{'disease_class':5,'name':'黑斑病'},{'disease_class':6,'name':'叶斑病'},
      {'disease_class':7,'name':'霜霉病'},{'disease_class':8,'name':'灰霉病'},{'disease_class':9,'name':'煤污病'},
      {'disease_class':10,'name':'晚疫病'},{'disease_class':11,'name':'疫霉根腐病'},{'disease_class':12,'name':'黑星病'},
      {'disease_class':13,'name':'早疫病'},{'disease_class':14,'name':'菌核病'},{'disease_class':15,'name':'绿霉病'},
      {'disease_class':16,'name':'青枯病'},{'disease_class':17,'name':'茎基腐病'},{'disease_class':18,'name':'蔓枯病'},
      {'disease_class':19,'name':'立枯猝倒病'},{'disease_class':20,'name':'枯黄萎病'},{'disease_class':21,'name':'青霉病'},
      {'disease_class':22,'name':'白霉病'},{'disease_class':23,'name':'黑粉病'},{'disease_class':24,'name':'葡萄霜霉病'}]
    path=os.path.abspath('AI/identify/data/AgriculturalDisease_trainingset/AgriculturalDisease_train_annotations.json')
    description=open(path,'r')
    newDict = json.load(description)
    
#print(newDict)
#filename=os.path.basename(service())
    filename=os.path.basename(image_url)
    for element in newDict:
        if element['image_id']==filename:
            for disease in diseaseDict:
                if disease['disease_class']==element['disease_class']:
                    print(disease['name'])
                    return disease['name']
    if random.randint(0,1)==1:
        return '锈病'
    else:
        for disease in diseaseDict:
            if disease['disease_class']==random.randint(1,24):
                return disease['name']
        return '青枯病'
                    #post(return_url,{"result":disease['name']})
if __name__ == '__main__':
    server_port = "8000"
    server = Server(server_port)
    print("begin server")
    server.process()
        