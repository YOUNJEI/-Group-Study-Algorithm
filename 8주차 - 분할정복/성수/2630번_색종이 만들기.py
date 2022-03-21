import sys
input = sys.stdin.readline
n = int(input())
colorpaper = []
cnt = []

for i in range(n):
    a = list(map(int, input().split()))
    colorpaper.append(a)


def bunhal(a, b, k):
    t = colorpaper[a][b]
    for i in range(a, a+k):
        for j in range(b, b+k):
            if t != colorpaper[i][j]:
                bunhal(a, b, k//2)
                bunhal(a, b+k//2, k//2)
                bunhal(a+k//2, b, k//2)
                bunhal(a+k//2, b+k//2, k//2)
                return

    if t == 0:
        cnt.append(0)
    else:
        cnt.append(1)



bunhal(0, 0, n)

print(cnt.count(0))
print(cnt.count(1))