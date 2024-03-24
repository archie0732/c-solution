# Strategy Game

[題目連結](https://vjudge.net/problem/Uva-12959)


* 每一輪賺到點數相比，看誰贏

### code

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int j, r;
    while (cin >> j >> r && j && r)
    {
        vector<int>v(j, 0);

        for (int i = 0;i < r;i++)
        {
            for (int k = 0;k < j;k++)
            {
                int tem;
                cin >> tem;
                v[k] += tem;
            }
        }

        int last_winner = 0;

        for (int i = 1;i < j;i++)
        {
            if (v[i] >= v[last_winner])last_winner = i;
        }

        cout << last_winner + 1 << endl;

    }

    return 0;
}
```
