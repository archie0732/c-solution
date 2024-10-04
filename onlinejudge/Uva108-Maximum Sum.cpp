#include <iostream>
#include <bits/stdc++.h>

/*
    2024-10-4
    前綴和 / 首碼和
*/

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grap(n, vector<int>(4)), prefix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tem;
            cin >> tem;
            prefix[i][j] = prefix[i][j - 1] + tem;
        }
    }

    int ans = 0;
    // 固定寬
    for (int i = 1; i <= n; i++)
    {
        // 拉伸:　由 i 至 j (i, i+1, i+2, ..... j)
        for (int j = i; j <= n; j++)
        {
            int sum = 0;
            for (int k = 1; k <= n; k++)
            {
                // 因為要包含 i 所以要 i - 1
                sum += prefix[k][j] - prefix[k][i - 1];
                ans = max(ans, sum);
                if (sum < 0)
                    sum = 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}