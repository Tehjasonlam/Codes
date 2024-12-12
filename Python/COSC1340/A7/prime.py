def isPrime(number):
    if (number == 0 and number == 1):
        return False
    
    for i in range(2,number):
        if (number % i == 0):
            return False
    return True
        
def HowManyPrimes(P):
    count = 0
    for i in range(2,P):
        if(isPrime(i)):
            count += 1
    return count 

def FindPrime(K):
    while(K > 2):
        if(isPrime(K)):
            return K
        K += 1
       


newnum = int(input("give me a number "))
if isPrime(newnum):
    print (newnum, "is Prime")
else:
    print(newnum, "is Not Prime")
    print("Number of primes less than", newnum, "is", HowManyPrimes(newnum))
    print("First prime greater than", newnum, "is", FindPrime(newnum))