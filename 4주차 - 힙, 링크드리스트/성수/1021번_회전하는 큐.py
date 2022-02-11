n, m = map(int, input().split())
a = [i for i in range(1, n+1)]
b = list(map(int, input().split()))
count = 0
for j in b:
    index = a.index(j)
    if index <= len(a)//2:
        for _ in range(index):
            a.append(a.pop(0))
            count += 1

    else:
        for _ in range(len(a)-index):
            a.insert(0, a.pop())
            count += 1
    a.pop(0)
print(count)