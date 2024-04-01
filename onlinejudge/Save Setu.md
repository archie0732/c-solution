# Save Setu

[題目連結](https://vjudge.net/problem/Uva-12403)


```cpp
#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main()
{
    int t;
    string sl;
    cin >> t;
    getline(cin, sl);
    ll money = 0;

    while (t--)
    {
        string s;
        getline(cin, s);

        if (s[0] == 'd')
        {
            stringstream ss(s);
            int tem;
            ss >> s >> tem;
            money += tem;
        }
        else
        {
            cout << money << endl;
        }

    }

    return 0;
}
```
