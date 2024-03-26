# Gourmet Games

[題目連結](https://vjudge.net/problem/UVA-11313)


* 2024/03/27 更新

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int p, num, show = 0, flag = 1;
        cin >> p >> num;

        while (true)
        {
            if (num > p)
            {
                flag = 0;
                break;
            }
            show += p / num;
            p = p / num + p % num;
            if (p == 1)
                break;
        }

        if (flag)
            cout << show << endl;
        else
            cout << "cannot do this" << endl;
    }
    return 0;
}
```

```cpp
#include<iostream>

//https://vjudge.net/problem/UVA-11313

using namespace std;


int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        int ans = 0;
        cin >> n >> m;
        while (n > 1)
        {
            n = n - m + 1;
            ans++;
        }
        if (n != 1)cout << "cannot do this" << endl;
        else cout << ans << endl;
    }

    return 0;
}

```
