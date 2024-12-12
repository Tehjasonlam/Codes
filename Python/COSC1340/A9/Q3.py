def para_basics(mypara):
    mypara = mypara.split()
    count = 0
    avgl = 0
    for word in mypara:
        avgl+=len(word)
        count+=1
    avg = int((avgl/count)*100)/100.00
    return avg

def long_words(mypara):
    mypara = mypara.split()
    longestWords=[mypara[0]]
    for word in mypara[1:]:
        if(len(longestWords[0])==len(word)):
            longestWords.append(word)
        elif(len(longestWords[0])<len(word)):
            longestWords=[word]
    return longestWords

"""
def long_words(mypara):
    phrase = mypara.split()
    longwords = []
    for word in phrase:
        if len(word)>=8:
            longwords.append(word)
    return longwords

def special_words(mypara):
    mypara = mypara.split()
    specialwords=[]
    rareLetters=["j","q","x","z"]
    for word in mypara:
        for letter in rareLetters:
            if(letter in word.lower()):
                specialwords.append(word)
                break
    return specialwords
"""
def special_words(mypara):
    mypara = mypara.split()
    special_words = []
    rareLetters=["j","q","x","z"]
    for word in mypara:
        for letter in rareLetters:
            if(letter in word.lower()):
                special_words.append(word)
    return special_words

def cool_para(mypara):
    rareLetters=["j","q","x","z"]
    for word in long_words(mypara):
        for letter in rareLetters:
            if(letter in word.lower()):
                return True
    return False


mypara = 'This animal is zebraaaaa. Other animal is foxxxxxxx.'
print('%.3f' %para_basics(mypara))
print(long_words(mypara))
print(special_words(mypara))
print(cool_para(mypara))

mypara = 'This is the second paragraph with a example input for test cases. We will talk about nutrition today.'
print('%.3f' %para_basics(mypara))
print(long_words(mypara))
print(special_words(mypara))
print(cool_para(mypara))

mypara = 'In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet hole, filled with the ends of worms and an oozy smell, no yet a dry, bare, sandy hole with nothing in it to sit down on or to eat; it was a hobbit-hole, and that means comfort.'

print('%.3f' %para_basics(mypara))
print(long_words(mypara))
print(special_words(mypara))
print(cool_para(mypara))