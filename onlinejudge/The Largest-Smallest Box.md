# The Largest/Smallest Box


[題目連結](https://vjudge.net/problem/UVA-10215#author=0)


#### 解題

>[!note]
>#### uva 與 瘋狂程設 不同
> 用cpp時uva 沒有用1e-8 wa  
>瘋狂程設則不會


* 根據題目意思 ==> 體積 (l-2x)(w-2x)x
* 微分 ==> $`wl - 4wx - 4lx - 12x^2 = 0`$

* 用$`x = \frac{-b- \sqrt{b^2 - 4ac}}{2a}`$



![](https://i.pixiv.cat/img-original/img/2024/02/21/11/50/39/116253722_p0.png)


#### code

```cpp

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define eee 1e-8

using namespace std;


int main()
{

    double l, w;
    while (cin >> l >> w)
    {
        double a = 12;
        double b = -4 * (w + l);
        double c = w * l;

        // (-b - sqrt(b^2-4ac))/2a
        double ans_1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a) + eee;

        double ans_3 = w < l ? w : l;

        printf("%.3lf 0.000 %.3lf\n", ans_1, ans_3 / 2 + eee);
    }
    return 0;
}
```
