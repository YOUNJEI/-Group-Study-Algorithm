# https://www.acmicpc.net/problem/1449

# n : 물이 새는 곳의 개수, l : 테이프 길이
n, l = map(int, input().split())
water = list(map(int, input().split()))
water.sort()

end = 0
count = 0

for tape in water:
    # 새로운 시작점이 이미 테이프가 붙여진 위치 안에 잇으면 또 붙일필요없음
    if tape > end:
        # 붙인 테이프가 끝나는 위치
        end = tape + l - 1
        count += 1

print(count)