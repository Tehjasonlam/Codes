#The function will always return the maximum value integer in the parameter intlist.
def amax(intlist):    
    maximum = 0
    for num in range(len(intlist)):
        if intlist[num] > maximum:            
            maximum = intlist[num]    
    return maximum

intList = [1,2,3,4,5,6,7,8,9,10]

print(amax(intList))