s = input()
freq = {}

for c in s:
    if not c in freq.keys():
        freq[c] = 1
    else:
        freq[c] += 1

total = 1
for c in freq.keys():
    total *= freq[c] + 1

print(total % 11092019)
