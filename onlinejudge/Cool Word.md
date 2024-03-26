# Cool Word

[題目連結](https://vjudge.net/problem/UVA-12820)

* 用map

```cpp
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n, turn = 1;

    while (cin >> n && n)
    {
        int cool = 0;

        while (n--)
        {
            int flag = 1;
            map<char, int>mp;
            string s;
            cin >> s;

            if (s.size() == 1)continue;
            for (int i = 0;i < s.size();i++)
            {
                mp[s[i]]++;
            }

            set<int>check;


            for (auto it : mp)
            {
                if (!check.count(it.second))
                {
                    check.insert(it.second);
                }
                else flag = 0;
            }

            if (flag)cool++;
        }
        cout << "Case " << turn++ << ": " << cool << endl;
    }

    return 0;
}
```
