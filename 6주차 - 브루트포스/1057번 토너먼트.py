# https://www.acmicpc.net/problem/1057

# n: 경기수, a: 지민, b: 한수
n, a, b = map(int, input().split())
count = 0

# 몫=몇번째 경기. 둘의 몫이 같아지는 때가 둘이 상대하게되는 경기
while a != b:
    a -= a // 2
    b -= b // 2
    count += 1
print(count)