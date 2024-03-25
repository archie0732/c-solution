# Nice Licence Plates 

[題目連結](https://vjudge.net/problem/Uva-12602)


* 按題意的去算

```cpp

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
    int t;
    string sl;
    cin >> t;
    getline(cin, sl);

    while (t--)
    {
        ll a = 0, b = 0, x = 0;
        string s;
        getline(cin, s);

        for (int i = 2;i >= 0;i--)
        {

            int c = s[i] - 'A';

            ll tem = pow(26, x);
            a += tem * c;

            x++;
        }
        //cout << a << endl;
        for (int i = 4;i < 8;i++)
        {
            b *= 10;
            b += s[i] - '0';
        }
        //cout << b << endl;

        if (abs(a - b) <= 100)
        {
            cout << "nice" << endl;
        }
        else cout << "not nice" << endl;

    }

    return 0;
}
```
