N = int(input())  
F = int(input())

for i in range(100):
    n=(N//100)*100+i
    if n%F==0:
        print(f"{i:02}")
        break
