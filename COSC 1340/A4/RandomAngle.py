import random
import math
import os

os.system("clear")

for i in range(3):
    Dangle = random.randint(0,180)
    Rangle = (Dangle * math.pi)/180

    print(f"The angle selected at random is {Dangle}")
    print(f"The value of sin( {Dangle} ) is {math.sin(Rangle)}")
    print(f"The Value of Cos( {Dangle} ) is {math.cos(Rangle)}")
    print(f"The value of sin^2( {Dangle} ) + cos^2( {Dangle} ) - 1 is : {(math.sin(Rangle))**2 + (math.cos(Rangle))**2 - 1}")

