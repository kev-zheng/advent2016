#! /usr/bin/env python3.

import pyperclip
import collections

lcount = lambda l, c: l.count(c)

message = []

lines = pyperclip.paste().split('\n')

print(*lines,sep="")

columns = [""]*len(lines[0])

for i in range(len(lines[0])):
    for j in range(len(lines)):
        columns[i] += lines[j][i]

for i in range(len(columns)):
    message.append(collections.Counter(columns[i]).most_common(1)[0][0])
print(*message,sep='')
print(*columns,sep="\n")
