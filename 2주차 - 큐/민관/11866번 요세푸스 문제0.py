# https://www.acmicpc.net/problem/11866
# rotate 안쓰고 카운트로 해결할라하면 시간초과뜸

from collections import deque

n, k = map(int, input().split())  # N : N명의 사람, K : 빼낼 순번

# 1~N명의 사람
people = [i+1 for i in range(n)]

# 방출된 사람 들어올 곳
out = []

q_people = deque(people)

while q_people:
    q_people.rotate((-1*k)+1)
    out.append(q_people.popleft())

print("<", end="")
print(*out, sep=", ", end="")
print(">", end="")

