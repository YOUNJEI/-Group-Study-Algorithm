n, m = map(int, input().split())

k=0
for i in range(n-m+1):
    print(k, k+1)
    k += 1

x = k-1
for j in range(m-2):
    print(x, k+1)
    k += 1