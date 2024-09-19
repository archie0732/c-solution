def slove():
    n, m = map(int, input().split())
    s = list(map(int, input().split()))

    s.sort()
    cur = s[-1]
    ans = []
    for _ in range(m):
        a, b, c = map(str, input().split())
        if a == "+":
            if int(b) <= cur and int(c) >= cur:
                cur += 1
                ans.append(str(cur))
            else:
                ans.append(str(cur))
        else:
            if int(b) <= cur and int(c) >= cur:
                cur -= 1
                ans.append(str(cur))
            else:
                ans.append(str(cur))

    print(" ".join(ans))


t = int(input())
for _ in range(t):
    slove()
