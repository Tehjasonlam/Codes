"""
def mystery(i,j,k):
    if (i<j):
        if(j<k):
            print(i,j,k)
        elif i<k:
            print(i,k,j)
        else:
            print(k,i,j)
    else:
        if(i<k):
            print(j,i,k)
        elif (j<k):
            print(j,k,i)
        else:
            print(k,j,i)
            
           
           
print(mystery(20,10,30))
"""
"""
def anotherMystery(i,j,k):
    if (i>j):
        if(j>k):
            print(i,j,k)
        elif i>k:
            print(i,k,j)
        else:
            print(k,i,j)
    else:
        if(i>k):
            print(j,i,k)
        elif (j>k):
            print(j,k,i)
        else:
            print(k,j,i)
            
print(anotherMystery(-35,21,0))
""" 
"""
def unknown(K):
    flag = True
    if K%3:
        return not flag
    return flag


print(unknown(4))
print(unknown(15))
""" 
"""
def unknown(K):
    flag = True
    if K%3:
        return not flag
    return flag


def U2(K):
    sum = 1
    for I in range(K):
        if (unknown(I) and I != 0):
            sum *= I
    return(sum)


print(U2(10))
"""

for num in range(30, 0, -3):
    if num % 2 == 0:
        print(num)
        
num = 30
while num > 5:
    if num% 2 == 0:
        print(num)
    num = num - 3