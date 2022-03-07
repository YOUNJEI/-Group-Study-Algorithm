import sys
input = sys.stdin.readline
t = int(input())

for i in range(t):
    n = int(input())
    score = []
    for j in range(n):
        x = tuple(map(int, input().split()))
        score.append(x)
    score.sort()
    interview = score[0][1]
    cnt = 1

    for k in range(1, n):
        if interview > score[k][1]:
            cnt += 1
            interview = score[k][1]

    print(cnt)