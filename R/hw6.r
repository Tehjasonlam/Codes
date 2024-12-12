n1 <- 33
x1bar <- 16.9
s1 <- 1.9

n2 <- 27
x2bar <- 15.3
s2 <- 2.2

ttest <- function(n1, n2, x1bar, x2bar, s1, s2) {
    a <- x1bar - x2bar
    b <- sqrt((((n1 - 1) * s1^2) + ((n2 - 1) * s2^2)) / (n1 + n2 - 2))
    c <- sqrt((1 / n1) + (1 / n2))
    X <- a / (b * c)
    return(X)
}
result <- ttest(n1, n2, x1bar, x2bar, s1, s2)
print(result)

confint <- function(n1, n2, x1bar, x2bar, s1, s2) {
    a <- x1bar - x2bar
    b <- sqrt((((n1 - 1) * s1^2) + ((n2 - 1) * s2^2)) / (n1 + n2 - 2))
    c <- sqrt((1 / n1) + (1 / n2))
    Llimit <- a - (1.672 * (b * c))
    Ulimit <- a + (1.672 * (b * c))
    int <- c(Llimit, Ulimit)
    return(int)
}

result <- confint(33, 27, 16.9, 15.3, 1.9, 2.2)
print(result)

cdf <- function(x) {
  ifelse(x < 0, 0, ifelse(x <= 3, (1/24) * x^3, 1))
}
d <- integrate(function(x) x * cdf(x), lower = 0, upper = 3)$value
print(d)

c <- uniroot(function(x) cdf(x) - 0.5, interval = c(0, 3))$root
print(c)

b <- integrate(function(x) (x - d)^2 * cdf(x), lower = 0, upper = 3)$value
print(b)

a <- integrate(function(x) cdf(x), lower = 1, upper = 1.5)$value
print(a)




