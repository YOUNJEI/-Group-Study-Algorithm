import heapq

def solution(scoville, K):
    heapq.heapify(scoville)

    answer = 0

    while len(scoville)>=2:
        a = heapq.heappop(scoville)
        if a >= K:
            return answer
        else:
            b = heapq.heappop(scoville)
            heapq.heappush(scoville, a+b*2)
            answer += 1

    if scoville[0] > K:
        return answer
    else:
        return -1



print(solution([1, 2, 3, 9, 10, 12], 7))