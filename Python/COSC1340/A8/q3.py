def up_Houston(refstring):
    new_string = " "
    if refstring.find("Houston") != -1:
        new_string = new_string + refstring.replace("Houston","Wonderful Houston",1)
    else:
        new_string = new_string + refstring
    return new_string

print(up_Houston("It is so hot in Houston area."))
print(up_Houston("Astros will play in Houston. It is very hot in Houston."))

