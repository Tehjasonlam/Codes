def IsExpired(months,decayRate):
    drug = 100
    for i in range(months):
        drug  = drug - (drug * (decayRate/100))
    if drug < 50:
        return True
    else:
        return False
    
print(IsExpired(10,10))
print(IsExpired(15,4))
print(IsExpired(1,51))
print(IsExpired(1,50))