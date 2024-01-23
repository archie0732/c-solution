# Can you slove it

[題目連結](https://vjudge.net/problem/UVA-10642)


#### 解題

* 第一排:(1,0) (0,1)
* 第二排:(2,0) (1,1) (0,2)
* 第四排以後以此類推

所以用等差數列總和即可

* 公式

$`S = {(a_1+a_n)*n}/{2} `$ 


* 最後再減去誤差值就行了(高度差距)



#### code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    int turn = 1;
    while (t--)
    {
        ll bx, by, fx, fy;
        cin >> bx >> by >> fx >> fy;

        //
        ll ans = (bx + by + fx + fy + 1) * (fx + fy - bx - by) / 2;
        ans += (fx - bx);
        // cout << tem << endl;

        cout << "Case " << turn << ": " << ans << endl;

        turn++;
    }
    return 0;
}
```
