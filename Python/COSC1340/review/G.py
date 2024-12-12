f = open("myPara.txt", 'r')
w = f.read().split()
for i in w:
    if len(i)//3 == 1:
        print(i)
