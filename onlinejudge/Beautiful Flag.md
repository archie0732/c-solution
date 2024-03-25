# Beautiful Flag 


[題目連結](https://vjudge.net/problem/Uva-12611)


* 按題意

```cpp
#include<bits/stdc++.h>

using namespace std;


int main()
{
    //r:s = 20: 100 ==> 100r=20s ==> r = 0.2s ==> 5r = s 
    //s:h = 10:6 ==> 10*h=6*s ==> h = 0.6s; 
    int t, turn = 1;
    cin >> t;

    while (t--)
    {
        cout << "Case " << turn++ << ":" << endl;
        int r;
        cin >> r;

        int s = r * 5;
        int h = (s * 0.6) / 2;
        int w_left = s * 0.45 * -1;
        int w_right = s * 0.55;

        cout << w_left << " " << h << endl;
        cout << w_right << " " << h << endl;
        cout << w_right << " " << -h << endl;
        cout << w_left << " " << -h << endl;
    }
    return 0;
}
```
