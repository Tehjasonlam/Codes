def list_letters(text):
    d={}
    for i in text:
        if(i not in d):
            d[i]=1
        else:
            d[i]=d[i]+1
    return d


def list_words(text):
    words=text.split()
    d={}
    for i in words:
        if(i not in d):
            d[i]=1
        else:
            d[i]=d[i]+1
    return d

text = "How much wood could a woodchuck chuck if a woodchuck could chuck wood?"
print(list_letters('Banana'))
print(list_letters(text))
print(list_words('Banana'))
print(list_words(text))