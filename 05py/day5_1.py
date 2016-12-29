#! /usr/bin/env python3.

import hashlib
import random

string = input()
counter = 0
passNum = 0

password = []

lower = 10000000
upper = 100000000

while True:
    print(*password,sep='',end='')
    print(random.randint(lower, upper), end='\r')
    hashInput = string + str(counter)
    result = hashlib.md5(hashInput.encode('utf-8')).hexdigest()
    if result[0:5] == "00000":
        password.append(result[5])
        lower /= 10
        upper /= 10
        passNum += 1
    counter += 1
    if passNum >= 8:
        break
print('\n')
print(*password,sep='')
