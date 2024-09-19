def slove():
    n, k = map(int, input().split())

    if k > n and k % n == 0:
        print(k // n)
    elif k > n and k % n:
        print(k // n + 1)
    elif n >= k and n % k == 0:
        print(1)
    else:
        print(2)


t = int(input())
for _ in range(t):
    slove()
