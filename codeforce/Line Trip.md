# Line Trip

#### 題目等級

* $`\textcolor{green}{易}`$
#### 題目

[題目連結](https://codeforces.com/problemset/problem/1901/A)

#### 解題


找出兩地最大的距離，記得**終點與最後一個加油站的距離要在*2**

#### code


```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
    題目: Line Trip
    題目來源:https://codeforces.com/problemset/problem/1901/A
    解題者:神里綾華的狗
    解題語言:C++
    
    使用技巧:greedy
    P.S.超簡單!!
*/

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n;
        cin >> n >> x;
        vector<int> v(n);
        cin >> v[0];
        int maxdc = v[0];
        for (int i = 1; i < n; i++)
        {
            cin >> v[i];
            maxdc = max(maxdc, v[i] - v[i - 1]);
        }
        maxdc = max(maxdc, (x - v[n - 1]) * 2);
        cout << maxdc << endl;
    }
    return 0;
}
```
