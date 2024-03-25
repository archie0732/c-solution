# I ❤ Pizza 

[題目連結](https://vjudge.net/problem/Uva-12626)



* 用map

![](https://pixiv.cat/117113547_0.jpg)

### code 


```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    // 1*M 3*A 2*R 1*G 1*I 1*T

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        map<char, int>pizza;

        for (int i = 0;i < s.size();i++)pizza[s[i]]++;

        vector<int>v(6, 0);

        v[0] = pizza['M'];
        v[1] = pizza['A'] / 3;
        v[2] = pizza['R'] / 2;
        v[3] = pizza['G'];
        v[4] = pizza['I'];
        v[5] = pizza['T'];

        sort(v.begin(), v.end());

        cout << v.front() << endl;


    }

    return 0;
}
```
