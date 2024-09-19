t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    mn = 10000
    for i in range(1, 11):
        tem = i - a + b - i
        mn = min(tem, mn)

    print(mn)
