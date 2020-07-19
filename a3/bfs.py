from collections import defaultdict
from math import *
def bfs(d,src):
    q=[]
    q.append(src)
    v[src]=1
    while q:
        s=q.pop(0)
        for i in d[s]:
            if v[i]==-1:
                v[i]=1
                q.append(i)
    return s

def bfsi(d,v,src):
    q=[]
    q.append(src)
    v[src]=0
    while q:
        s=q.pop(0)
        for i in d[s]:
            if v[i]==-1:
                v[i]=v[s]+1
                q.append(i)
    return v[s]

'''main'''
n,m,f=map(int,input().split())
d=defaultdict(list)
for i in range(m):
    x,y=map(int,input().split())
    d[x].append(y)
    d[y].append(x)
v={}
for i in range(1,n+1):
    v[i]=-1
ma=1
l1=[]
for i in range(1,n+1):
    if v[i]==-1:
        p=bfs(d,i)
        l1.append(p)
for i in range(1,n+1):
    v[i]=-1
for i in l1:
    di=bfsi(d,v,i)
    ma=max(ma,di)
print(ceil((ma+1)/f))
