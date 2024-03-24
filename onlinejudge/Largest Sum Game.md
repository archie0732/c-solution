# Largest Sum Game

[題目連結](https://vjudge.net/problem/Uva-12640)

* **求連續最大值** ，所以當總和小於0時，就直接捨棄他


```cpp
#include<bits/stdc++.h>

using namespace std;


int main()
{
    string s;

    while (getline(cin, s))
    {
        int n;
        vector<int> v;
        stringstream ss(s);
        while (ss >> n)v.push_back(n);

        int sum = 0, max_sum = 0;
        for (int i = 0;i < v.size();i++)
        {
            sum += v[i];
            max_sum = max(max_sum, sum);
            sum = sum > 0 ? sum : 0;
            //cout << sum << endl;
        }
        cout << max_sum << endl;
    }

    return 0;
}
```


