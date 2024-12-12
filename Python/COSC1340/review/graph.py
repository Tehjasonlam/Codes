def  string_basics(text):
    text = text.replace(',','').replace('.','')
    textnp = text.replace(' ','').replace(',', '').replace('.', '')
    data = text.split()
    count = 0
    avgl = 0
    for word in data:
        avgl+=len(word)
        count+=1
    avg = float((avgl/count)*100)/100
    res_lst = [len(data), len(textnp), avg]
    return res_lst

def word_length_select(text, length, option):
    string = []
    text = text.replace(',','').replace('.','')
    text = text.split(" ")
    
    if option == 0:
        for word in text:
            if len(word) == length:
                string.append(word)
    elif option == 1:
        for word in text:
            if len(word) < length:
                string.append(word)
    elif option == 2:
        for word in text:
            if len(word) > length:
                string.append(word)
 
             
    return string

def longest_word_length(text):
    text = text.split()
    longword =  max(text, key=len)
    longword = len(longword)
    return longword
    


def word_length_counter(text):
    d = {}
    
    text = text.replace(',','').replace('.','')
    text = sorted(text, key=len)
    
    for word in longest_word_length(text):
        d[len(word)] += 0
    
    for word in text:
        d[len(word)] += 1
    
    return d
   
    
def data_graph(data):

    for num in range(1,max(data)+1):
        print(f"{str(num).rjust(2)} ",end ="")
        
        if num in data:
            count = 1 * data[num]
            print(f"[{count}]: ",end ="")
            print("o"*data[num])
            
         
        else:
            print("")
    
    return

def data_graph_file(data):
    filename = "data_graph.txt"
    outFile = open(filename ,"w")
    for num in range(1,max(data)+1):
        print(f"{str(num).rjust(2)} ",end ="")
        
        if num in data:
            count = 1 * data[num]
            print(f"[{count}]: ",end ="")
            print("o"*data[num])
            
         
        else:
            print("")
    
    outFile.close()
    return

text = "We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defence, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America."

print(string_basics(text))
print(word_length_select(text, 7, 0))
print(longest_word_length(text))
print(word_length_counter(text))
data_graph(word_length_counter(text))
data_graph_file(word_length_counter(text))

