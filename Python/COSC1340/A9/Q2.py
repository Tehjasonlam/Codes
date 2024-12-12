def common_items(reflist,mylist,inplace):
    li = []
    for i in mylist:
        if i in reflist:
            li.append(i)
    if inplace==True:
        mylist.clear()
        for j in li:
            mylist.append(j)
                
    return li 


druglist = ['tylenol','ibuprofen','pepto-bismol','sudafed','robitussin']
myneeds = ['glucose', 'pepto-bismol', 'tylenol']
inplace = False
print(common_items(druglist, myneeds, inplace))
print(myneeds)
inplace = True
print(common_items(druglist, myneeds, inplace))
print(myneeds)

druglist_1 = ['A','E','S','X']
mylist_1 = ['B','S','Y']
inplace = False
print(common_items(druglist_1, mylist_1, inplace))
print(mylist_1)
inplace = True
print(common_items(druglist_1, mylist_1, inplace))
print(mylist_1)