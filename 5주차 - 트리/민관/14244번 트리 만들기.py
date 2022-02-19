# https://www.acmicpc.net/problem/14244

# n : 노드의 개수, m : 리프의 개수(리프는 root 포함임)
n, m = map(int, input().split())

count = 1
tree = []

# 일단 리프가 2개가 되는 지점까지 가지를 뻗치고, 그 이후에는 같은 층에서 1개씩 가지만 늘리면 됨
for i in range(n-m+1):
    if i != n-m:
        tree.append((i,i+1))
    else:
        if count == m:
            break
        for j in range(n-m+1, n):
            tree.append((i, j))
            count += 1

for i in range(len(tree)):
    print(tree[i][0], tree[i][1])