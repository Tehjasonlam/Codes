def NumRepeats(num1,num2,num3):
    if num1 == num2 and num2 == num3:
        return 2
    elif num1 == num2 or num2 == num3 or num1 == num3:
        return 1
    else:
        return 0



print(NumRepeats(5, 9, 4))
print(NumRepeats('5', '9', '5'))