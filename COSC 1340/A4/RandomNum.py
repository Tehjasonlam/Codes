import random
import os

os.system("clear")

maxNum= 0
meanNum = 0

print("The random numbers are", end = " ")
for i in range(10): # i = 0 1 2 3 4 5 6 7 8 9
    number = random.randint(20,100)
    print(f"{number}",end = " ")
    maxNum = max(maxNum, number)
    meanNum += number

meanNum /= 10
print(f"The highest number is {maxNum}")
print(f"The mean of the 10 random numbers is {meanNum:.1f}")