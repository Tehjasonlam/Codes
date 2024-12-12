fh = open('myfile.txt','r')
for line in fh.readlines():
    items = line.split()
    if len(items[0]) < 5:      
        print(items[0])
fh.close()