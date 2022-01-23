import sys
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

stack = []
b = [-1]*n
for i in range(n):
    while stack and stack[-1][0] < a[i]:
        value, idx = stack.pop()
        b[idx] = a[i]
    stack.append((a[i], i))
for j in b:
    print(j, end=" ")