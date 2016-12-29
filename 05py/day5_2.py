#! /usr/bin/env python3.

import hashlib
import random

string = input()
counter = 0
passNum = 0
password = [None]*8

while True:
    hashInput = string + str(counter)
    result = hashlib.md5((string + str(counter)).encode('utf-8')).hexdigest()
    if result[0:5] == "00000" and result[5].isdigit() and int(result[5]) < 8 and password[int(result[5])] is None:
        password[int(result[5])] = result[6]
        passNum += 1
    counter += 1
    if counter % 10000 == 0:
        for i in range(8):
            if password[i] is None:
               print(random.randint(0, 9),end='')
            else:
                print(password[i],end='')
        print(end='\r')
    if passNum >= 8:
        break
print('\n')
print(*password,sep='')
