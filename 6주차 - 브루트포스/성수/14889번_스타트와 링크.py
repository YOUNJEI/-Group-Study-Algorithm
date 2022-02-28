import sys
import itertools

input = sys.stdin.readline

n = int(input())
synergy = [[0]*(n+1)]
num = [i for i in range(1, n+1)]
for i in range(n):
    x = list(map(int, input().split()))
    x.insert(0, 0)
    synergy.append(x)

combi = list(itertools.combinations(num, n//2))

minn = 1000000
for j in range(len(combi)//2):
    start = 0
    link = 0
    fcbn = list(itertools.combinations(combi[j], 2))
    bcbn = list(itertools.combinations(combi[-1-j], 2))
    for k in fcbn:
        start += synergy[k[0]][k[1]] + synergy[k[1]][k[0]]

    for l in bcbn:
        link += synergy[l[0]][l[1]] + synergy[l[1]][l[0]]

    if abs(start-link)<minn:
        minn = abs(start-link)


print(minn)