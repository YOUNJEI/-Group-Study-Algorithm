# https://programmers.co.kr/learn/courses/30/lessons/42626

import heapq


def solution(scoville, K):
    # 접근 1 : 오름차순 정렬후 0,1을 섞어서 mix로 만들고 mix + a[2]부터 끝까지를 새로운 배열에 집어넣음, 이를 반복 - 답은 잘나오지만 효율성 개박살
    # 접근 2 : heapq모듈을 사용해서 같은 방식으로 진행.
    answer = 0
    heapq.heapify(scoville)  # 스코빌지수 배열을 최소 heap으로 만들어줌

    while scoville[0] < K:
        # pop을 해가면서 계산
        mix = heapq.heappop(scoville) + heapq.heappop(scoville)*2
        heapq.heappush(scoville, mix)
        answer += 1
        if len(scoville) == 1 and scoville[0] < K:
            answer = -1
            break

    return answer