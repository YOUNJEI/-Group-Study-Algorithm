import sys
n = int(sys.stdin.readline())
stack = []

for _ in range(n):
    command = sys.stdin.readline().split()

    if len(command) == 2:
        stack.append(command[1])

    else:
        if 'top' in command:
            if stack:
                print(stack[-1])
            elif not stack:
                print(-1)

        elif 'pop' in command:
            if stack:
                print(stack.pop())
            elif not stack:
                print(-1)

        elif 'size' in command:
            print(len(stack))

        else:
            if stack:
                print(0)
            elif not stack:
                print(1)