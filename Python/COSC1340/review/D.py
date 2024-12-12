fruitlist = ['Bananas', 'Grapes', 'Apples']

if 'apple' in fruitlist:
    print(True)
else:
    print(False)
    
    
    
isapple = False
for i in fruitlist:
    if i == 'apple':
        isapple = True
print(isapple)

for i in fruitlist:
    if i == 'apple':
        isapple = True
    else:
        isapple = False
print(isapple)


isapple = False
for i in range(len(fruitlist)):
    if fruitlist[i] == 'apple':
        isapple = True
print(isapple)