#! /usr/bin/env python3.

import pyperclip
import re


def findssl(outer, inner):
    for i in range(len(outer)):
        for c in range(len(outer[i])-2):
            if outer[i][c] == outer[i][c+2]:
                aba = outer[i][c:c+3]
                bab = aba[1] + aba[0] + aba[1]
                for j in range(len(inner)):
                    for cc in range(len(inner[j])):
                        if inner[j][cc:cc+3] == bab:
                            return True
    return False

input = pyperclip.paste().split('\n')

hypernetRegex = re.compile(r'\[.*?\]')
ipRegex = re.compile(r'^.*?\[|\].*?\[|\].*?$')

validIPs = 0

for s in range(len(input)):
    if findssl(ipRegex.findall(input[s]), hypernetRegex.findall(input[s])):
            validIPs += 1
print(validIPs)
