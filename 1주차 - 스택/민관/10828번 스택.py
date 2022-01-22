'''
push x : 정수 x를 스택에 넣음
pop : 스택에서 가장 위에 있는 정수 빼고 출력, 아무것도 없으면 -1
size : 스택에 들어있는 정수 개수 출력
empty : 스택 비어잇으면 1, 아니면 0 출력
top : 스택의 가장 위에 있는 정수 출력, 없으면 -1
'''
import sys


n = int(sys.stdin.readline())  # 입력할 명령 수
stack = []

for _ in range(n):
    order = sys.stdin.readline().split()
    if order[0] == 'push':
        stack.append(order[1])
    if order[0] == 'pop':
        if len(stack):
            print(stack.pop())
        else:
            print(-1)
    if order[0] == 'size':
        print(len(stack))
    if order[0] == 'empty':
        if len(stack):
            print(0)
        else:
            print(1)
    if order[0] == 'top':
        if len(stack):
            print(stack[-1])
        else:
            print(-1)
