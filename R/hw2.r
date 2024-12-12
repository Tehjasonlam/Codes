Codata = read.csv("HW2Q1.csv", header = TRUE)
class(Codata)
names(Codata)
writeLines("\n")
"a"
mean(Codata$Enroll)
median(Codata$Enroll)
writeLines("\n")
"b"
fivenum(Codata$Enroll)
writeLines("\n")
"c"
quantile(Codata$Enroll, .7)
writeLines("\n")
"d"
new = Codata$Enroll[-c(69,70)]
quantile(new, .7)
writeLines("\n")
"e"
boxplot(Codata$Enroll, horizontal = TRUE)

writeLines("\n")
writeLines("\n")
"f"
stem(Codata$S.F.Ratio, 1)
"Skewed right"
fivenum(Codata$S.F.Ratio)
"median"
median(Codata$S.F.Ratio)
"range"
range(Codata$S.F.Ratio)

"No Outliers"