R = lambda: map(int, input().split())

(t,) = R()

while t:
    t -= 1
    (n,) = R()
    l = list(R())
    flag, ans = 1, 0
    for i in l:
        ans += (flag) * i
        flag *= -1
    print(ans)
