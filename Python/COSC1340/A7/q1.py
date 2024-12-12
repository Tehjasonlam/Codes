
def CreditPay(rate, payment, verbose):
    balance = 1000
    month = 1
    paid = 0
    
    while balance > payment:
        balance = balance * (1 + rate / 100) - payment
        paid += payment
    
        if verbose:
            print(f"Balance after month {month} is $ {balance}.")
            
        month += 1
    print(f"Final payment is % {balance}")
    print(f"Total amount paid is $ {balance + paid}")
    
    return month

nmonths = CreditPay(2.5,99+1,False)
print("Number of months to pay off is", nmonths)

nmonths = CreditPay(2.5,100,True)
print("Number of months to pay off is", nmonths)