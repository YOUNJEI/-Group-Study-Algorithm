import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
route = []
for _ in range(n):
    row = list(map(int, input().split()))
    route.append(row)

result = []
for _ in range(n):
    row = [0 for _ in range(n)]
    result.append(row)

for i in range(n):
    for j in range(n):
        q = deque()
        if route[i][j] == 1:
            q.append([i, j])
            while q:
                x, y = q.popleft()
                result[x][y] = 1
                for k in range(n):
                    if route[y][k] == 1 and result[x][k] == 0:
                        q.append([x, k])

for i in range(n):
    for j in range(n):
        print(result[i][j], end = " ")
    print()
