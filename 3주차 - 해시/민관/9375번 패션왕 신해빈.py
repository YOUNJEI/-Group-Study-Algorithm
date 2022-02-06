# https://www.acmicpc.net/problem/9375

tc = int(input())

for i in range(tc):
    # 갖고있는 옷의 개수
    n = int(input())
    answer = 1

    dict = {}
    for j in range(n):
        name, kinds = map(str, input().split())
        # 종류가 이미 키에 있다면 값 1씩 올려주기
        if kinds in dict.keys():
            dict[kinds] += 1
        # 없으면 1부터 시작
        else:
            dict[kinds] = 1

    for key in dict:
        answer *= (dict[key]+1)

    print(answer-1)
