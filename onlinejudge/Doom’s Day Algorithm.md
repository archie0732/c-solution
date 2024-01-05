# Doom’s Day Algorithm

[題目連結](https://onlinejudge.org/external/120/12019.pdf)

屬於比較討厭的CPE 一星題，如果你沒有想到投機的寫法的話XD

#### 解題

0. 建表 ==> 星期一至日
1. 建表==>題目給了好幾個用的星期一，去推剩下的最後建成表
2. 去把輸入的日去減掉輸入月的對應表
>大於 0 ==> %7 去對照星期表，得解
>小於 0 ==> %7 + 7 去對照星期表，得解



![](https://images8.alphacoders.com/120/1208462.jpg)
#### code 

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define Mo "Monday"
#define Tu "Tuesday"
#define We "Wednesday"
#define Th "Thursday"
#define Fr "Friday"
#define Sa "Saturday"
#define Su "Sunday"

/*
    解題: Doms Day Algorithm
    解題者:神里綾華的狗

    這次這樣亂搞(一堆定義)主要是防抄用
*/
using namespace std;

/*
    note :(all monday)

    4/4 ==>擬用
    6/6
    8/8
    10/10
    12/12
*/

// 建置表 ==> 每月的個星期一
const vector<int> Ever_Mon_Monday = {-1, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
// 建置表 ==> 星期
const vector<string> day = {Mo, Tu, We, Th, Fr, Sa, Su};

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, d;
        cin >> m >> d;
        int key = d - Ever_Mon_Monday[m];
        key = key % 7;
        if (key >= 0)
        {
            cout << day[key] << endl;
        }
        else
        {
            key = 7 + key;
            cout << day[key] << endl;
        }
    }
    return 0;
}
```
