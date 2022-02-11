# https://www.acmicpc.net/problem/2346

from collections import deque

n = int(input())  # 숫자의 개수

# enumerate를 쓰면 인덱스와 입력된 값이 같이 들어감
dq = deque(enumerate(map(int, input().split())))
ans = []

while dq:
    # 제일 왼쪽의 인덱스(풍선번호)와 순서를 뽑아내기
    idx, num = dq.popleft()
    # print(idx, num)
    # 0부터 시작이니 1씩 더해서 answer에 입력
    ans.append(idx+1)

    # 돌려돌려
    if num > 0:
        dq.rotate(-(num-1))
    else:
        dq.rotate(-num)

print(*ans)



