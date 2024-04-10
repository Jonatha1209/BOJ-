t = int(input())
for i in range(t):
    o = 1
    a,b = map(int,input().split())
    for j in range(b):
        o = (o*a)%10
        
    if o == 0:
        o = 10
    
    print(o)
