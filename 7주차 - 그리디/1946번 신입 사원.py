# https://www.acmicpc.net/problem/1946

import sys
input = sys.stdin.readline

# 테스트 케이스 수
tc = int(input())

for _ in range(tc):
    # 몇명 입력?
    n = int(input())
    # 일단 1등 1명은 무조건 포함
    answer = 1
    # 점수 저장하기
    score = list()
    for i in range(n):
        score.append(list(map(int, input().split())))

    # 일단 서류 점수만 정렬
    score.sort()
    # 서류 1등의 면접 순위(면접 커트라인)
    interview = score[0][1]
    for i in range(1, n):
        # 이전 사람보다 서류점수는 낮지만 면접 순위는 높음
        if score[i][1] < interview:
            answer += 1
            interview = score[i][1]

    print(answer)





