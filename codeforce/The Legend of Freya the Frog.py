t = int(input())


for _ in range(t):
    a, b, c = map(int, input().split())
    x = a // c + (a % c > 0)
    y = b // c + (b % c > 0)
    ans = 2 * max(x, y)
    if x > y:
        ans -= 1

    print(ans)
"""

11 + 9 = 20 

20 / 3 = 6

"""
