def slove():
    n = int(input())
    l = list(map(int, input().split()))
    s = input()
    dp = [0] * (n + 1)
    vist = [False] * (n)

    for i in range(n):
        if not vist[i]:
            now = i
            cir = []
            count = 0
            while not vist[now]:
                vist[now] = True
                cir.append(now)  # 同路徑都視為一個鏈，即路過的黑子數量相同
                if s[now] == "0":
                    count += 1
                now = l[now] - 1

            for j in cir:
                dp[j] = count
    ans = list(map(str, dp[0:-1]))
    print(" ".join(ans))


t = int(input())

for _ in range(t):
    slove()
