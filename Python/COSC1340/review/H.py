a = [1,2,3,4,5,6,7,8,9,10]
total = 0

for i in a[::2]:
    total += a[-i]  

print(total)
