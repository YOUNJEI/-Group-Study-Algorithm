n = int(input())

card = []
for i in range(n):
    card.append(int(input()))
card.sort()
deque = {}
for j in card:
    deque[j] = 0
for k in card:
    deque[k] += 1

a = 0
m = 0
for l in deque:
    if deque[l]>a:
        a = deque[l]
        m = l

print(m)