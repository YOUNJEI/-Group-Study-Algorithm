t = int(input())

for i in range(t):
    n = int(input())
    cloth = {}
    closet = []
    for j in range(n):
        designation, part = input().split()
        closet.append((designation, part))
        cloth[part] = 0

    for k in range(n):
        cloth[closet[k][1]] += 1

    x = 1
    for key in cloth:
        x *= (cloth[key]+1)

    print(x-1)