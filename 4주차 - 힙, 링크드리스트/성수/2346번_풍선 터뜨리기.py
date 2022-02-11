n = int(input())
number = list(map(int, input().split()))
balloon = []
for k in range(n):
    balloon.append((number[k], k+1))

for i in range(n-1):
    b = balloon.pop(0)
    number.pop(0)

    print(b[1], end=" ")
    if b[0]>0:
        for j in range(b[0]-1):
            number.append(number.pop(0))
            balloon.append(balloon.pop(0))
    else:
        for l in range(b[0]*(-1)):
            number.insert(0, number.pop())
            balloon.insert(0, balloon.pop())

print(balloon[0][1])
