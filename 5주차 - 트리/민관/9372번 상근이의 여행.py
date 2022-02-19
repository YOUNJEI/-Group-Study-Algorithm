# https://www.acmicpc.net/problem/9372
import sys
input = sys.stdin.readline

# 테스트 케이스 수 입력
tc = int(input())

# 테스트 케이스 숫자 안에서
for i in range(tc):
    # n: 국가의 수, m: 비행기 종류
    n, m = map(int, input().split())
    for _ in range(m):
        a, b = map(int, input().split())
    print(n-1)