munseo = list(input())
word = list(input())
cnt = 0
while len(munseo)>=len(word):
    x = 0
    for i in range(len(word)):
        if word[i]!=munseo[i]:
            x = 1
            break

    if x== 0:
        for j in range(len(word)):
            munseo.pop(0)
        cnt += 1
    else:
        munseo.pop(0)

print(cnt)