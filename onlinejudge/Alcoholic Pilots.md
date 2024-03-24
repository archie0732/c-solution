# Alcoholic Pilots 


[題目連結](https://vjudge.net/problem/Uva-12970)


* $`{d_1}/{v_1} : {d_2}/{v_2} ==> d_1*v_2 : d_2*v_1`$


```cpp

#include<bits/stdc++.h>
#define ll long long 

using namespace std;


int main()
{
    ll v1, d1, v2, d2, turn = 1;

    while (cin >> v1 >> d1 >> v2 >> d2 && (v1 + v2 + d1 + d2))
    {

        cout << "Case #" << turn++ << ": ";
        ll t1, t2;
        t1 = v1 * d2;
        t2 = v2 * d1;

        if (t1 > t2)
        {
            cout << "You owe me a beer!" << endl;
        }
        else cout << "No beer for the captain." << endl;

        ll time = v1 * d2 + v2 * d1, av = v1 * v2 * 2;

        ll sum = __gcd(time, av);

        time /= sum;av /= sum;

        cout << "Avg. arrival time: ";
        if (av == 1)
        {
            cout << time << endl;
        }
        else
        {
            cout << time << "/" << av << endl;
        }

        //cout << sum << endl;


    }

    return 0;
}
```
