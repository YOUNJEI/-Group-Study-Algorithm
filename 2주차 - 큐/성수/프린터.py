def solution(priorities, location):
    answer = 0
    q = []
    for i in range(len(priorities)):
        q.append((priorities[i], i))

    while priorities:
        if q[0][0] == max(priorities):
            if q[0][1] ==location:
                answer += 1
                break
            else:
                priorities.pop(0)
                q.pop(0)
                answer += 1
        else:
            priorities.append(priorities.pop(0))
            q.append(q.pop(0))

    return answer