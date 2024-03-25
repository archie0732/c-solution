#  Zapping

[題目連結](https://vjudge.net/problem/UVA-12468)


* 列舉各種轉台方式，並取最小


```cpp

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int from, to;

    while (cin >> from >> to && from >= 0 && to >= 0)
    {
        vector<int>v(3, 0);
        v[0] = abs(to - from);
        v[1] = 100 - from + to;
        v[2] = 100 - to + from;
        // 98 ==> 3 ==> 99 0 1 2 3 //5
        // 3 ==> 98 ==> 2 1 0 99 98//5

        sort(v.begin(), v.end());

        cout << v[0] << endl;
    }
    return 0;
}
```
