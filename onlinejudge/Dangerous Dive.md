# Dangerous Dive

[題目連結](https://vjudge.net/problem/Uva-12650)



* 第一次看到`present error ` 是在句尾忘記加空格

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n, r;
    while (cin >> n >> r)
    {
        map<int, int>mp;
        for (int i = 1;i <= n;i++)
        {
            mp[i] = 1;
        }

        for (int i = 0;i < r;i++)
        {
            int p;
            cin >> p;
            if (mp[p] > 0)mp[p]--;
        }

        int flag = 0;
        for (auto it : mp)
        {
            if (it.second > 0)
            {
                cout << it.first << " ";
                flag++;
            }
        }
        if (n == r)cout << "*";
        cout << endl;
    }

    return 0;
}
```
