L = int(input())
N = int(input())
b = []
c = []
for i in range(N):
    a = input()
    c.append(0)
    b.append(a)
for i in range(N-1):
    for j in range(L):    
        if b[i][j] != b[i+1][j] :
            c[i+1] += 1
for i in range(len(b)):
    if i != 0 :
        if c[i] > 2 :
            print(b[i-1])
            break
    if i == len(b)-1 :
        if c[i] <= 2 :
            print(b[i])