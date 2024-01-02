# Bar Code (2023 12 CPE 最後一題)

* 因為要交作業的關係:解題+拍片+剪 大概花了兩天(所以就放在一起了)


[題目連結](https://cpe.cse.nsysu.edu.tw/cpe/test_data/2023-12-12)

第一次講解，有點生疏還請見笑  
[解題影片](https://youtu.be/zBYfRvUoFtM?si=_ATyR_B_Ms6_s8gH)



#### code 

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

// array  ==> int a[100][100]={};
vector<vector<ll>> dp;

ll slice(int n, int k, int m)
{
    if (k == 1 && n > m)
        return 0;

    if (dp[n][k] != -1)
        return dp[n][k];

    if (k == 1)
        return 1;

    ll ans = 0;
    int tem = n - m;

    for (int i = n - 1; i >= max(tem, 1); i--) // 6 3  / 5 3 / 4 3
        ans += slice(i, k - 1, m);

    dp[n][k] = ans;

    return dp[n][k];
}

int main()
{
    int n, k, m;

    while (cin >> n >> k >> m) // ctrl + C
    {
        dp.assign(n + 1, vector<ll>(k + 1, -1));

        cout << slice(n, k, m) << endl;
    }

    return 0;
}

```
