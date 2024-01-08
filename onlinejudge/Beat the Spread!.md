# Beat the Spread!

[題目連結](https://onlinejudge.org/external/108/10812.pdf)


#### 解題

解方程式  
反推回來  

a + b = add   
a - b = sub   

* 就等於

2 * a = add + sub  ==>  a = (add + sub)/2

b = add - a


假如  a 或 b 
>1. 非整數
>2. <0
輸出: impossible


#### code 

![](https://th.bing.com/th/id/OIP.EAW2pD6WytnXThslbRR51gHaLH?rs=1&pid=ImgDetMain)


```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        vector<ll> ans;

        if (b > a)
        {
            cout << "impossible" << endl;
        }
        else
        {
            bool flag = 0;
            if ((a + b) % 2 == 1)
            {
                flag = 1;
            }
            ans.push_back((a + b) / 2);
            ans.push_back(a - ans[0]);
            sort(ans.begin(), ans.end());

            if (ans[0] < 0 || ans[1] < 0 || flag == 1)
            {
                cout << "impossible" << endl;
            }
            else
            {
                cout << ans[1] << " " << ans[0] << endl;
            }
        }
    }
    return 0;
}
```

