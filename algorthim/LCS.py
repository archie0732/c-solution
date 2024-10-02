def LCS(s1: str, s2: str):
    n = len(s1)
    m = len(s2)

    dp = [[0] * (m + 1) for _ in range(n + 1)]  # 建立(n + 1) * (m + 1)的dp圖表
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i] == s2[j]:
                dp[i][j] += dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j + 1])

    return dp[n][m]
