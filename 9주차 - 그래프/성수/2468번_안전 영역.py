import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
city = []
for h in range(n):
    g= list(map(int, input().split()))
    city.append(g)

z = []
for i in city:
    for v in i:
        z.append(v)


f = list(set(z))

result = []
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

for j in f:
    dp = []
    for _ in range(n):
        s = [0 for _ in range(n)]
        dp.append(s)

    for k in range(n):
        for l in range(n):
            if city[k][l] <= j:
                dp[k][l] = 1

    cnt = 0
    for x in range(n):
        for y in range(n):
            if dp[x][y] == 0:
                cnt += 1
                q = deque()
                q.append([x, y])
                while q:
                    w, e = q.popleft()
                    dp[w][e] = 1
                    for p in range(4):
                        nx = dx[p] + w
                        ny = dy[p] + e
                        if 0<=nx<n and 0<=ny<n and dp[nx][ny] == 0 and (nx, ny) not in q:
                            q.append((nx, ny))
    result.append(cnt)

if max(result) == 0:
    print(1)
else:
    print(max(result))
