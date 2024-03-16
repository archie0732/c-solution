# Three-square


[題目連結](https://vjudge.net/problem/UVA-11342)



```cpp
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;


/*
    https://vjudge.net/problem/UVA-11342

    解題: 這種三點、三邊的都可以透過找出兩邊來推第三邊是不是正確的
*/
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        int flag = 0, res;
        vector<int> ans(3);
        double tem;

        for (int i = 0;n >= i * i && flag == 0;i++)
        {
            for (int j = i;n >= j * j && flag == 0;j++)
            {
                tem = sqrt(0.0 + n - i * i - j * j);
                res = sqrt(n - i * i - j * j);

                if (tem == res)
                {
                    flag = 1;
                    ans[0] = i;
                    ans[1] = j;
                    ans[2] = res;
                    break;
                }
            }
        }

        if (flag)
        {
            sort(ans.begin(), ans.end());
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        }
        else cout << "-1" << endl;
    }

    return 0;
}
```
