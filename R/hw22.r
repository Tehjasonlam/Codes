
Codata = read.delim("https://www.math.uh.edu/~charles/data/Montana.txt")
class(Codata)
names(Codata)

barplot(table(Codata$Region))
barplot(table(Codata$State))
barplot(table(Codata$Politics))