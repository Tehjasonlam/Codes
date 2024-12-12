milesStart = float(input("Enter the odometer reading at the start of the trip in miles: "))
milesEnd = float(input("Enter the odometer reading at the end of the trip in miles: "))
gasStart = float(input("Enter the amount of gasoline at the start of the trip in gallons: "))
gasEnd = float(input("Enter the amount of gasoline at the end of the trip in gallons: "))
gasPrice = float(input("Enter the price of gas in dollars per gallon: "))

miles =  milesEnd - milesStart
gas = gasStart - gasEnd
mpg = miles / gas
cost = (gas * gasPrice) / miles
totalmiles = mpg * gasEnd

print(f"Miles per gallon for the car is {mpg:.2f}")
print(f"The cost of the trip in dollars per mile is {cost:.2f}")
print(f"Total number of miles car can continue is {totalmiles:.1f}")