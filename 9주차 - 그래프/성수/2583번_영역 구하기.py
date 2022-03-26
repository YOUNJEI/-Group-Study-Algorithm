import sys
from collections import deque
input = sys.stdin.readline

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

m, n, k = map(int, input().split())
paint = []
for _ in range(k):
    row = list(map(int, input().split()))
    paint.append(row)

gridpaper = []
for _ in range(n):
    row = [0 for _ in range(m)]
    gridpaper.append(row)

for _ in range(k):
    sx, sy, ex, ey = paint.pop()
    for i in range(sx, ex):
        for j in range(sy, ey):
            gridpaper[i][j] = 1


result = []
for i in range(n):
    for j in range(m):
        cnt = 0
        if gridpaper[i][j] == 0:
            q = deque()
            q.append([i, j])
            while q:
                cnt += 1
                x, y = q.popleft()
                gridpaper[x][y] = 1
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if 0<=nx<n and 0<=ny<m and gridpaper[nx][ny] == 0 and [nx, ny] not in q:
                        q.append([nx, ny])
            result.append(cnt)

print(len(result))
result.sort()
for i in range(len(result)):
    print(result[i], end = " ")