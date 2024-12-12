from math import ceil

length = float(input("Length of the rectangle? "))
width = float(input("Width of the rectangle? "))

perimeter = (length + width) * 2
area = length * width
can = ceil(area / 100)

print(f"The perimeter of the rectangle with length {length},and width {width}, is {perimeter:.2f} feet")
print(f"The area of the rectangle with length {length},and width, {width}, is {area:.2f} square feet")
print("The number of cans needed to paint the rectangle are",can)