def match_words_dict(inputFilename, Wordlist):
    f = open(inputFilename, 'r') 
    readline = f.read().split() 
    f.close()

    d = {} 
    for word in Wordlist:
        count = readline.count(word)
        dict[word] = count
    return d


wlist1 = ["Jack", "Jill", "up", "river"]
worddic = match_words_dict("JackAndJill.txt", wlist1)
print(worddic)

wlist1 = ["up", "rise", "we", "nation"]
worddic = match_words_dict("TheHillWeClimb.txt", wlist1)
print(worddic)