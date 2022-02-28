n, kim, lim = map(int, input().split())
cnt = 0

while True:
    if kim % 2 == 0:
        kim = kim // 2
    else:
        kim = kim // 2 + 1

    if lim % 2 == 0:
        lim = lim // 2
    else:
        lim = lim // 2 + 1

    cnt += 1

    if kim == lim:
        print(cnt)
        break