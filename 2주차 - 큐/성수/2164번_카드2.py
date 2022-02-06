import sys
from collections import deque

n = int(sys.stdin.readline())  # 카드 개수

card = deque()  # 카드덱 구성
for i in range(1, n+1):
    card.append(i)

for _ in range(n-1):
    card.popleft()  # 위에 하나 버리고
    card.append(card.popleft())  # 맨 위 카드 맨 아래로

print(card.pop())  # 남은 마지막 카드 출력