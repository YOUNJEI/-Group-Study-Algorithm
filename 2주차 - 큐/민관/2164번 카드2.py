# https://www.acmicpc.net/problem/2164 카드 2

from collections import deque

n = int(input())  # 숫자 입력
card = []

for i in range(n):
    card.append(i+1)

q_card = deque(card)

while len(q_card) != 1:
    q_card.popleft()  # 맨 앞의 숫자 버리기
    q_card.append(q_card.popleft())  # 맨 앞의 숫자 뒤에 붙이기

print(*q_card)
