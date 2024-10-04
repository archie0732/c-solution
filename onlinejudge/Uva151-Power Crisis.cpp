#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int m)
{
    vector<int> dp(n, 0);

    dp[1] = 1; // 初始化: 只有1人 => 1號存活

    for (int i = 2; i <= n; i++) // 假如有i個塔 => 結束一回合會變 i-1 然後再變 i-2, i-3.... 直到 1 。所以這裡進行反推
    {
        /*
            在 i 人的情況下 可以代換為: a = i - m ^ n (m 為要跳過的人數，n 為最接近 i 的 m 次方)
            活下來的人為: m * a + 1
            所以透過 在 i 人的情況下找到 倖存者 可以再透過 加上 m - 1 來找到 i+1 的倖存者
        */
        dp[i] = (dp[i - 1] + (m - 1)) % i + 1;
    }

    return dp[n];
}

// 由 n 回推至 1 的
int josephus2(int n, int k)
{
    return n > 1 ? (josephus(n - 1, k) + k - 1) % n + 1 : 1;
}

int main()
{
    int n;
    while (cin >> n && n)
    {

        int m = 2, ans = 0;

        if (n == 13)
        {
            cout << 1 << endl;
            continue;
        }
        // 因為重  1 開始所以由 1 開始，目標 -1
        while (josephus2(n - 1, m) != 12)
            m++;
        cout << m << endl;
    }

    return 0;
}