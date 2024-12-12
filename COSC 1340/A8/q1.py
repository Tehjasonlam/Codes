def uniqueletters(refstring):
    new_string = ""
    
    for i in refstring:
        if i not in new_string:
            new_string += i
    
    return new_string

str=input("Enter String: ")
print(uniqueletters(str))