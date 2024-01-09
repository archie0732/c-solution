#  Back to High School Physics


[題目連結](https://onlinejudge.org/external/100/10071.pdf)


#### 解題

* $`v_t  =  v_0 t + a t `$
* $`d={v_0}^{2} t+1/2at`$

依照題目意思(求2t位移)
* $`d=1/2*2^2*a*t^2`$
* $`a*t^2`$ == $`vt`$

* 所以得: $`d=2*t*v`$

#### code 

![](https://a-static.besthdwallpaper.com/pretty-anime-girl-kamisato-ayaka-genshin-impact-wallpaper-800x600-118901_17.jpg)   
```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int v, a;

    while (cin >> v >> a)
    {
        // v = a*t
        // v/a = t

        // 位移 =  1/2 * a * (2*t)^2
        //     = 2 * a * t ^ 2

        cout << floor(2 * v * a) << endl;
    }
    
    return 0;
}
```
