import random
import math
import os

os.system("clear")

radius = float(input("Please enter a radius Value: "))

realA = math.pi * (radius ** 2)

pa = 3.1 * (radius ** 2)
pb = 3.14 * (radius ** 2)
pc = 3.141 * (radius ** 2)

piA = ((realA - pa) / ((realA + pa) / 2 )) * 100
piB = ((realA - pb) / ((realA + pb) / 2 )) * 100
piC = ((realA - pc) / ((realA + pc) / 2 )) * 100

print(f"The real area of the circle is : {realA:.12f}")
print(f"with pi= 3.1 , percentage difference {piA:.12f} %")
print(f"with pi= 3.14 , percentage difference {piB:.12f} %")
print(f"with pi= 3.141 , percentage difference {piC:.12f} %")