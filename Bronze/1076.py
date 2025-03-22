def r(c1,c2,c3):v={'black':0,'brown':1,'red':2,'orange':3,'yellow':4,'green':5,'blue':6,'violet':7,'grey':8,'white':9};return(v[c1]*10+v[c2])*(10**v[c3])
def i1():return input().strip()
def m():c1=i1();c2=i1();c3=i1();print(r(c1,c2,c3))
m()
