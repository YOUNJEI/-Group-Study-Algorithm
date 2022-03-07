n, l = map(int, input().split())
position = list(map(int, input().split()))

position.sort()
cnt = 0
while position:
    x = position.pop(0)
    cnt += 1
    while position and position[0]-x <= l-1:
        position.pop(0)

print(cnt)
