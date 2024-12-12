def what_is_it(intList):
    value = 0
    for i in range(len(intList)):
        if intList[i]%2 == 0:
            value += intList[i]
        if intList[i]%3 == 0:
            value -= intList[i]
    return value

intList = [2,3,4,5]
print(what_is_it(intList))