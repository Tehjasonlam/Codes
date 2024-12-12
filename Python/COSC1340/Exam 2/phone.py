def clear_phone_number(num):
    if num.isdigit():
        out = [(num[i:i+3]) for i in range(0, len(num), 3)]
        print(f"1_" + out[0] + "_" + out[1] + "_" + out[2]+out[3])
    else:
        num = num.replace('(', ' ').replace(')', ' ').replace('-', ' ')
        num = num.split()
        print(f"1_" + num[0] + "_" + num[1] + "_" + num[2])
    return

    
    
print(clear_phone_number("(987)654-3210"))
print(clear_phone_number("876-543-2109"))
print(clear_phone_number("(765) 432 1098"))
print(clear_phone_number("7776543210"))
