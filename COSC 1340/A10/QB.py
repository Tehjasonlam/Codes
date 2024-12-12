def QB_search(filename, searchterm):
    myFile = open(filename, 'r')
    name = []
    for i in myFile:
        qb = i.split()
        if searchterm in qb[1]:
            name.append(qb[0])
    myFile.close()
    return name


def QB_great(filename):
    myFile = open(filename, 'r') 
    name = []
    for i in myFile:
        qb = i.split()
        if float(qb[9][0:4]) > 60 and int(qb[7]) and int(qb[7]) > int(qb[8])*3:
            name.append(qb[1])
    myFile.close()
    return name

def QB_legend(filename):
    myFile = open(filename, 'r')
    name = []
    for i in myFile:
        qb = i.split()
        if float(qb[9][0:4]) > 60 and int(qb[7]) and int(qb[7]) > int(qb[8])*3:
            name.append(qb[1])
    myFile.close()
    return name
    

myFile = "qbdata.txt"
print(QB_search(myFile, 'Manning'))
print(QB_search(myFile, 'McCoy'))
print(QB_search(myFile, 'Patton'))
print(QB_search(myFile, 'an'))
print(QB_great(myFile))
print(f"{QB_legend(myFile)[0]} is the legendary QB!")