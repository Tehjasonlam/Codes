import random

def sumseries(N,K):
    sum = 0
    for i in range(K):
        sum = sum + N + i
    return sum

def sumrandseries(N,K):
    sum = 0 
    for i in range(K):
        sum = sum + random.randint(N, N + K)
    return sum

def compareseires(N,K):
    rand = sumrandseries(N,K)
    difference = sumseries(N,K) - rand
    return sumseries(N,K),rand, difference

myN = int(input("Input Number: N =  "))
myK = int(input("Input Number: K =  "))


for i in range(10):
    answer = compareseires(myN, myK)
    print(f"Difference between sumseries ({answer[0]}) and sumrandseries ({answer[1]}) is {answer[2]}")    

