#! /usr/bin/env python3.

import pyperclip
import re

def findabba(chunks):
    boolList = []
    for i in range(len(chunks)):
        boolList.append(False)
        for c in range(len(chunks[i])):
            if(chunks[i][c:c+2] == chunks[i][c+2:c+4][::-1] and
               chunks[i][c:c+2] != chunks[i][c+2:c+4]):
                boolList[-1] = True
                break
    return any(boolList)
input = pyperclip.paste().split('\n')

hypernetRegex = re.compile(r'\[.*?\]')
ipRegex = re.compile(r'^.*?\[|\].*?\[|\].*?$')

validIPs = 0

for s in range(len(input)):
    if not findabba(hypernetRegex.findall(input[s])):
        if findabba(ipRegex.findall(input[s])):
            validIPs += 1
print(validIPs)
