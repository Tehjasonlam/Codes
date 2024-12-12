""" 
x = 135
y = 64
q = x // y
r = x % y
p = x/y

print("Q is", q, "R is",r,"P is", p)
print(f"Q is {q} R is {r} P is {p:.2f}")  
"""

""" 
for i in range(0, 21, 3):
    print(i, end = ' ') 
"""


"""    
val = 9

for i in range (6, -12, -3):
    val = val + i

print(val)
"""
"""
a = 7 
b = 50
c = 20 // 7
d = "4"
b = b % a - 1

print(2*str(a)+str(c)+str(b)+d)
"""

"""
import turtle
wn = turtle.Screen()
polygon = turtle.Turtle()

for i in [30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30]:
    polygon.forward(75)
    polygon.left(i)

wn.exitonclick()
"""

"""
month = int(input("What Month is it? "))
day = int(input("What Day is it? "))
print(f"It has been {(month * 30 + day - 30):.0f} days since New Year!")
"""

"""
for i in range(1,4):
    print(f"Calculating x ** {i}")
    for j in range(1,7,2):
        print(j**i)
    print("=" * i)"""

"""
radius = float(input("Enter radius"))
pi = 3.14
pm = 2 * pi * radius
print("Perimeter is ", pm)
"""