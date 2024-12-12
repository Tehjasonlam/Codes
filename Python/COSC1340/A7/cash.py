seller = input("Hi Fun Cart Seller, what is your name? ")
ballCost = float(input("What is the price of a Balloon today? "))
popCost = float(input("What is the price of a Popsicle today? "))

print(f"Balloons are ${ballCost:.2f} each. Popsicles are ${popCost:.2f} each.")

tot_ball = 0
tot_pop = 0
tot_bill = 0

customer = input("Who is the next customer? ")

while seller != customer:
    ball =  int(input(f"Balloons are ${ballCost:.2f} each. How many Balloons? "))
    pop =  int(input(f"Popsicles are ${popCost:.2f} each. How many Popsicles? "))

    bill = ball * ballCost + pop * popCost
    
    print(f"{customer} you bought {ball} Balloons and {pop} Popsicles. \nYour bill is ${bill:.2f}")
    
    tot_ball += ball
    tot_pop += pop
    tot_bill += bill
    
    customer = input("Who is the next customer? ")
    
print(f"{seller}, it is time to close the store. \nWe sold {tot_ball} Balloons and {tot_pop} Popsicles for a total of ${tot_bill:.2f}")
    