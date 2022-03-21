n, r, c = map(int, input().split())

arr = []
for i in range(2**n):
    a = [0]*(2**n)
    arr.append(a)


def zzz(a, b, n, num):
    if n>=2:
        zzz(a, b, n-1, num+0*4**(n-1))
        zzz(a, b+2**(n-1), n-1, num+1*4**(n-1))
        zzz(a+2**(n-1), b, n-1, num+2*4**(n-1))
        zzz(a+2**(n-1), b+2**(n-1), n-1, num+3*4**(n-1))
        return

    if n==1:
        arr[a][b] = num
        num += 1
        arr[a][b+1] = num
        num += 1
        arr[a+1][b] = num
        num += 1
        arr[a+1][b+1] = num
        num += 1
    return
zzz(0, 0, n, 0)
print(arr[r][c])