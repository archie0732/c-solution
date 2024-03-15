# Maximum Product


[題目連結](https://vjudge.net/problem/UVA-11059)



```cpp
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// a 要設成0

int main()
{

    int n, turn = 1;
    while (cin >> n)
    {

        vector<int>board(n);
        for (int i = 0;i < n;i++)
        {
            cin >> board[i];
        }
        long long ans = 0;
        for (int i = 0;i < n;i++)
        {
            long long tem = 1;
            for (int j = i;j < n;j++)
            {
                tem *= board[j];
                ans = max(ans, tem);
            }
        }
        cout << "Case #" << turn << ": The maximum product is " << ans << "." << endl << endl;
        turn++;
    }

    return 0;
}
```
