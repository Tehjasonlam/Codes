file =  open("studentdata.txt", "r") 
data = file.readlines()

arr = {}

for i in data:     
    grade = i.split()   
    arr[grade[0]] = grade[1:]
for i, j in arr.items():   
    cumlative = 0.1 * int(j[0]) + 0.4 * int(j[1]) + 0.2 * int(j[2]) + 0.3 * int(j[3]) 
    print(f" {i} has a cumulative score of {cumlative:.2f}")    
