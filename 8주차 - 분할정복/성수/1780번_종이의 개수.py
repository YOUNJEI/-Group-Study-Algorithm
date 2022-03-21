import sys
input = sys.stdin.readline

n = int(input())
paper = []
cnt=[]
for i in range(n):
    a = list(map(int, input().split()))
    paper.append(a)

def bunhal(a, b, n):
    t = paper[a][b]
    for i in range(a, a+n):
        for j in range(b, b+n):
            if paper[i][j] != t:
                newn = n // 3
                for mi in range(0, 3):
                    for mj in range(0, 3):
                        bunhal(a + mi * newn, b + mj * newn, newn)
                return

    if t==0:
        cnt.append(0)
    elif t==-1:
        cnt.append(-1)
    else:
        cnt.append(1)

bunhal(0, 0, n)
print(cnt.count(-1))
print(cnt.count(0))
print(cnt.count(1))