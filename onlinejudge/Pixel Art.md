# Pixel Art 

[題目連結](https://vjudge.net/problem/Uva-13171)

* 跟吹喇叭那堤相比就簡單許多

### code 


```cpp
#include<bits/stdc++.h>

using namespace std;



int main()
{

    map<char, vector<int>>color;

    //M Y C
    color['R'] = { 1,1,0 };
    color['G'] = { 0,1,1 };
    color['V'] = { 1,0,1 };
    color['B'] = { 1,1,1 };


    int t;
    cin >> t;

    while (t--)
    {
        string s;
        int flag = 1;
        vector<int>can_use(3, 0);
        for (int i = 0;i < 3;i++) cin >> can_use[i];

        cin >> s;

        for (int i = 0;i < s.size() && flag;i++)
        {
            if (isalpha(s[i]))
            {
                if (s[i] == 'M')
                {
                    if (can_use[0] > 0)can_use[0]--;
                    else flag = 0;
                }
                else if (s[i] == 'Y')
                {
                    if (can_use[1] > 0)can_use[1]--;
                    else flag = 0;

                }
                else if (s[i] == 'C')
                {
                    if (can_use[2] > 0)can_use[2]--;
                    else flag = 0;
                }
                else
                {
                    char c = s[i];

                    for (int j = 0;j < color[c].size();j++)
                    {
                        if (color[c][j])
                        {
                            if (can_use[j] > 0)can_use[j]--;
                            else flag = 0;
                        }
                    }
                }

            }
        }

        if (flag)
        {
            cout << "YES " << can_use[0] << " " << can_use[1] << " " << can_use[2] << endl;
        }
        else cout << "NO" << endl;

    }

    return 0;
}
```
