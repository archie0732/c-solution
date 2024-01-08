# odd sum 

[題目連結](https://onlinejudge.org/external/107/10783.pdf)


#### 解題

1. 把 a 跟 b 變成基數(如果是偶數 : a++,b--)
2. 從 a 開始 ==> 跳 2 到 b 算總和


#### code 

![](https://th.bing.com/th/id/OIP.Lqe-ODl_XCzG9RjhufDStgHaKS?rs=1&pid=ImgDetMain)

```cpp
#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    int turn = 1;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a % 2 == 0)
            a++;
        if (b % 2 == 0)
            b--;
        ll ans = 0;
        for (int i = a; i <= b; i += 2)
        {
            ans += i;
        }
        cout << "Case " << turn << ": " << ans << endl;
        turn++;
    }

    return 0;
}
```
