
n = int(input())
s = input()
l = s.split(" ")

for i in range(n):
    l[i] = int(l[i])

k=[]

z=0
o=0

for i in range(n):
    for j in range(i,n):
        for h in range(i,j+1):
            if l[h]==0:
                z+=1
            if l[h]==1:
                o+=1
        k.append(z-o)
        z=0
        o=0

k.sort()
t = k[-1]
j=0
for i in range(n):
    if l[i]==1:
        j+=1

print(j+t)










