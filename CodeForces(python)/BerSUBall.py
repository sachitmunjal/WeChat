n = int(input())
s = input()
b = s.split(" ")
for i in range(n):
    b[i] = int(b[i])
    
m = int(input())
d = input()
g = d.split(" ")
for i in range(m):
    g[i]= int(g[i])
b.sort()
g.sort()
p=0
t=0

for i in range(n):
    for j in range(t,m):
        if int(b[i])-int(g[j])==0 or int(b[i])-int(g[j])==-1 or int(b[i])-int(g[j])==1:
            p+=1
            t=j+1
            break
print(p)