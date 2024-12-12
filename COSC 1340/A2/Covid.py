from math import ceil

pop = 330
numVax = 32
vaxRate = 1.2

weeks = float(input("Target time periods (in weeks)"))
days = weeks * 7 
vaxPer = (numVax + vaxRate * days) / pop * 100
needRate = ((80 * pop /100) - numVax) / days

print(f"Percentage of population vaccinated by the end of the target period ({days} or {weeks} week(s)) is {vaxPer:.2f}")
print(f"Vaccination rate needed to reach heard immunity (80% of population) is {needRate:.2f} million per day.")
