from math import lcm
from itertools import combinations

n=list(map(int,input().split()))
m=float('inf')
for c in combinations(n,3):
    a,b,c = c
    m = min(m,lcm(lcm(a,b) , c))
print(m)
