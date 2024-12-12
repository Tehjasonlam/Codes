from math import ceil

pop = 330
numVax = 40
vaxRate = 1.5
startDay = 10
endDay = 20
newTot = 0 

dailyInc = float(input("Enter the Percent Daily Increase Rate: "))
dailyInc = dailyInc / 100

for i in range(0,startDay + 1):
    vaxRateInc = vaxRate * (dailyInc + 1) **i
    newTot = newTot + vaxRateInc
    print(f"On September {startDay + i}, {vaxRateInc:.3f} million were vaccinated")
print()

totalPer = ((newTot + numVax) * 100)/ pop
print(f"\nBy September {startDay + i}, {totalPer:.3f} % of the population is vaccinated")
