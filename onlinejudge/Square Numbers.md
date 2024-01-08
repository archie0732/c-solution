#  Square Numbers

[題目連結](https://onlinejudge.org/external/114/11461.pdf)

#### 解題

從 a 開始到 b 
>開根號，如果是整數 ==> ans++
>開根號，如果不是整數 ==> 沒事

#### code 

![](https://w.wallha.com/ws/13/MgdWx8jl.jpg)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{

    while (1)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b && b == 0)
            return 0;
        int ans = 0;
        for (int i = a; i <= b; i++)
        {
            double tem = sqrt(i);
            if (floor(tem) == tem)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```
