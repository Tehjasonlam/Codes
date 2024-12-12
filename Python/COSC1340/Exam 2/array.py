a=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
total = 0

for i in a[::3]:
    total += a[-i]
print(total)