"""you ask a friend to send you the function to determine if a number is prime or not. 
Unfortunately, it gets scrambled in the transfer. 
Unscramble the lines of code below to restore this function."""
# 1 def is_prime(num):
# 2 for i in range(3,num,2):
# 3 if num == 2:
# 4 if num % i == 0:
# 5 if num % 2 == 0:
# 6 return False
# 7 return False
# 8 return True 
# 9 return True

#1, 3, 8, 5, 6, 2, 4, 7, 9 

def is_prime(num):
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3,num,2):
        if num % i == 0:
            return False
        return True
            
        
num = 3
print(is_prime(num))