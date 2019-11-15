from sys import *

s = stdin.readline().rstrip()
freq = {}

for c in s:
    if not c in freq.keys():
        freq[c] = 1
    else:
        freq[c] += 1

total = 1
for c in freq.keys():
    total *= freq[c] + 1

stdout.write(str(total % 11092019) + '\n')
