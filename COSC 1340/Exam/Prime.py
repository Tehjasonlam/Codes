def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

def PrimeNumbers(howmany):
    prime = []
    for i in range(2,howmany):
        if howmany%i == 0:
            continue
        else
            prime.append(howmany)
    


    return prime




howmany = int(input("Enter a number "))
if isPrime(howmany):
    if howmany > 7:
        print (PrimeNumbers)
    else:
        print(" ")
else:
    print(" ")
