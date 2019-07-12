# -*- coding: utf-8 -*-
"""
Created on Thu Jul 11 10:22:32 2019

@author: xiaoyifu
"""

import socket
import os
import sys
import struct

prefix='E:/match/tianchi_agriculture/AI/identify/data/test/'

def sockClient():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect(('127.0.0.1', 8000))
    except socket.error as msg:
        print(msg)
        print(sys.exit(1))

    while True:
        #filepath = input('input the file: ')
        filepath=prefix+'00bcc8a469696ad21157c9e1872cbec5.jpg'
        # filepath = 'test.png'
        fhead = struct.pack(b'128sl', bytes(os.path.basename(filepath), encoding='utf-8'), os.stat(filepath).st_size)
        s.send(fhead)
        print('client filepath: {0}'.format(filepath))

        fp = open(filepath, 'rb')
        while 1:
            data = fp.read(1024)
            if not data:
                print('{0} file send over...'.format(filepath))
                break
            s.send(data)
        s.close()
        break


if __name__ == '__main__':
    sockClient()
