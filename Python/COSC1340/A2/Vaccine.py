from math import ceil

pop = 330
numVax = 40
vaxRate = 1.5


weeks = int(input("Target time periods (in weeks)"))
days = weeks * 7 

vaxRate2 = float(input("Daily vaccination increase rate (in   %)"))
rate = (vaxRate2 / 100) * vaxRate

vaxPer = (numVax + (vaxRate * days) + (rate * days * (days -1) / 2))/pop * 100
print(f"Percentage of population vaccinated by the end of the target period ({days} or {weeks} week(s)) is {vaxPer:.2f}")

needRateInc = (((pop * .80) - (numVax + vaxRate * days))/ ((vaxRate * days * (days -1))/ (100 * 2)))
print(f"Daily increase rate needed to reach heard immunity (80% of population) is {needRateInc:.2f} million per day.")
