# Inception

[題目連結](https://vjudge.net/problem/Uva-13055)


* 要會用`stringstream`

### code

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string sl;
    int t;
    cin >> t;
    getline(cin, sl);
    vector<string> v;

    while (t--)
    {
        string s, name;

        getline(cin, s);

        if (s[0] == 'S')
        {
            stringstream ss;
            ss.str(s);
            ss >> s >> name;
            v.push_back(name);
            //cout << name << endl;
        }
        else if (s[0] == 'T')
        {
            if (v.empty())
            {
                cout << "Not in a dream" << endl;
            }
            else cout << v.back() << endl;
        }
        else if (s[0] == 'K')
        {
            if (!v.empty())
            {
                v.pop_back();
            }
        }
    }


    return 0;
}
```
