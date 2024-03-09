# Is This Integration ?



[題目連結](https://vjudge.net/problem/UVA-10209)



#### 解題



[連結](https://a7069810.pixnet.net/blog/post/395133313-%5buva10209%5d-is-this-i)



>[!note]
>### 注意
>input 有可能是0


![](https://i.pixiv.cat/img-original/img/2023/03/14/00/00/43/106191873_p0.jpg)



#### code


```cpp

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define PI acos(-1.0)

using namespace std;



int main()
{
    double edge;
    while (cin >> edge)
    {
        if (edge == 0)cout << "0.000 0.000 0.000" << endl; continue;
        // 正方形面積
        double q = edge * edge;
        // 方格面積
        double ans_3 = q - 2 * (PI / 12 * q) - (0.5 * q * sqrt(3.0) / 2);

        //點面積
        double ans_2 = q - (q * PI / 4) - ans_3 * 2;

        //斜面面積
        double ans_1 = (q * PI / 4) - 0.5 * q - ans_2;
        printf("%.3lf %.3lf %.3lf\n", 2 * ans_1, 4 * ans_2, 4 * ans_3);
    }

    return 0;
}
```
