def FileBasics(filename):
    myFile = open(filename, "rt")
    data = myFile.read()
    words = data.split()
    res_lst = [len(data), len(words)]
    print(res_lst)
    myFile.close()
    
def Matchwords(inputFilename, outputFilename, Wordlist):
    inpFile = open(inputFilename,"r")
    data = inpFile.read()
    outFile = open(outputFilename,"w")
    for word in Wordlist:
        count = data.count(word)
        cont = word + "\t" + str(count) + "\n" 
        outFile.write(cont)
        outFile.write("\n")
        inpFile.close()
    

 
    
    
    

FileBasics("JackAndJill.txt")
FileBasics("TheHillWeClimb.txt")
wlist1 = ["Jack", "Jill", "up", "river"]
Matchwords("JackAndJill.txt", "outfile1.txt", wlist1)
wlist2 = ["up ", "rise ", "we ","nation "]
Matchwords("TheHillWeClimb.txt", "outfile2.txt", wlist2)