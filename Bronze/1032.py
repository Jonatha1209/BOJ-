n=int(input())
file = [input() for _ in range(n)]
p = ''
for i in range(len(file[0])):
    char = file[0][i]
    same = all(files[i] == char for files in file)
    if same:p+=char
    else:p+="?"
print(p)
