# The Hotel with Infinite Rooms

[題目連結]()


#### 解題

S ==> 第一天來的客人(數量)

* 規則:

1. 群組的數量(人數)決定他們要住幾天
2. 上一批客人離開後，會再來上一組客人數量+1的群體住(上一組客人住天數+1天)
3. 每一次只會有一組人馬


直接加 ans = n + (n+1) + (n+2) + (n+3) +....(n+k)  ==> 直到 >= 第D天


#### code 

![](https://embed.pixiv.net/artwork.php?illust_id=91398038)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    ll S, D;

    while (cin >> S >> D)
    {
        ll the_day = 0;
        for (int i = S;; i++)
        {
            the_day += i;
            if (the_day >= D)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
```
