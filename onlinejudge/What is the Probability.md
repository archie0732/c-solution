# What is the Probability?

[題目連結](https://zerojudge.tw/ShowProblem?problemid=e510)

[解題連結](https://ithelp.ithome.com.tw/articles/10340964)

#### code 
```cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*
    題目:What is the Probability?(CPE 一星題)
    題目連結:https://zerojudge.tw/ShowProblem?problemid=e510

    解題者:神里綾華的狗
    解題技巧:背公式，沒了
    解題連結:
*/

int main()
{

    int t;

    cin >> t;
    while (t--)
    {
        double p;
        int n, i;
        /*
        第一場 * 無窮級數公式
        (1-p)^(k-1)  * p *1/(1-(1-p)^n)==>場次趨近無限大
        */
        cin >> n >> p >> i;
        if (p == 0)
        {
            cout << "0.0000\n";
        }
        else
        {
            // (1-p)^(k-1) * p
            double a = pow(1.0 - p, i - 1) * p; // pow取次方
            // (1-p)^n;
            double b = pow(1.0 - p, n);
            // setprecision(x) 取到小數點後第x位
            cout << fixed << setprecision(4) << a / (1.0 - b) << endl;
        }
    }
    return 0;
}
```
