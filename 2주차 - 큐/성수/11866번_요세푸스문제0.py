n, k = map(int, input().split())
a = []
c = []
for i in range(1, n+1):
    a.append(i)

index = k-1

for j in range(n):
    if index >= len(a):
        index = index%len(a)
    c.append(a.pop(index))
    index += k-1

print("<", end="")
for k in range(n-1):
    print(c[k], end=", ")
print(c[-1], ">", sep="")