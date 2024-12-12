Codata = read.csv("Tigers.csv", header = TRUE)
class(Codata)
names(Codata)

writeLines("\n")
"a"
table(Codata$activity)

writeLines("\n")
"b"
barplot(table(Codata$activity))

writeLines("\n")
"c"
pie(table(Codata$activity))

