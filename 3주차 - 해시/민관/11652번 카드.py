# https://www.acmicpc.net/problem/11652

import sys
input = sys.stdin.readline

# 가지고있는 숫자 카드의 개수
n = int(input())

# 카드 들어갈 리스트 딕셔너리로 선언
card_deck = {}

for i in range(n):
    # 카드의 숫자 입력받기
    card = int(input())
    if card in card_deck:
        card_deck[card] += 1
    else:
        card_deck[card] = 1

# 딕셔너리.items() = 딕셔너리 키, 값 쌍을 얻어옴
# 첫번째 인자(키)를 기준으로 내림차순(-), 그다음 값을 기준으로 오름차순
result = sorted(card_deck.items(), key = lambda x:(-x[1], x[0]))
print(result[0][0])