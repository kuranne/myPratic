N = int(input())
while True:
    bol = []
    prime = []

    c = [int(mem) for mem in str(N)]

    for i in range(len(c)//2):
        if c[i] == c[len(c)-1-i]:
            bol.append(True)   

    if len(bol) == len(c)//2 :
        if N % 2 == 0 or N == 1:
            continue

        for z in range(3,int(N**0.5)+1, 2):
            if N % z == 0:
                prime.append(z)

        if len(prime) == 1:
            print(N)
            break

    N += 1