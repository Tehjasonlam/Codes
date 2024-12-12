def NominalGrade(Ascore,Escore):
    weighted_score = ( Ascore + Escore ) / 2
    if weighted_score >= 86:
        return 4
    elif weighted_score >= 74:
        return 3
    elif weighted_score >= 62:
        return 2
    elif weighted_score >= 50:
        return 1
    else:
        return 0


def TrueGrade(Ascore,Escore):
    score = NominalGrade(Ascore,Escore)
    if Escore >= 86:
        EGrade = 4
    elif Escore >= 74:
        EGrade = 3
    elif Escore >= 62:
        EGrade = 2
    elif Escore >= 50:
        EGrade = 1
    else:
          EGrade =  0
          
    if score == EGrade or score == (EGrade + 1):
        score = score
    else:
        score = EGrade + 1
          
    if score == 4:
        return 'A'
    elif score == 3:
        return 'B'
    elif(score == 2):
        return 'C'
    elif(score == 1):
        return 'D'
    else:
        return 'F'
          
    

print(NominalGrade(96, 84))
print(TrueGrade(96, 84))

print(NominalGrade(96, 54))
print(TrueGrade(96, 54))

print(NominalGrade(54, 96))
print(TrueGrade(54, 96))

print(NominalGrade(36, 54))
print(TrueGrade(36, 54))

print(NominalGrade(100, 49))
print(TrueGrade(100, 49))