# https://www.acmicpc.net/problem/1543

# 문서
doc = input()

# 찾고 싶은 단어
word = input()

# word 기준으로 split 해버리면 split된 갯수가 word의 갯수
sp_word = doc.split(word)

print(len(sp_word)-1)