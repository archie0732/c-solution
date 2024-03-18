# Ugly Numbers


[題目連結](https://vjudge.net/problem/UVA-136)



* 建立表格（紀錄重複），記得句號


## code 


```cpp

#include <iostream>
#include <vector>
#include <set>

#define ll long long

using namespace std;

int main()
{
    ll a, counter = 1;

    vector<int> v(1505);
    v[0] = 1;
    v[1] = 1;
    ll p2 = 1, p3 = 1, p5 = 1;

    set<ll> s;

    int save = 2;

    while (save <= 1500)
    {
        if (v[p2] * 2 <= v[p3] * 3 && v[p2] * 2 <= v[p5] * 5)
        {
            if (!s.count(v[p2] * 2))
            {
                s.insert(v[p2] * 2);
                v[save++] = v[p2] * 2;
                p2++;
            }
            else
            {
                p2++;
            }
        }
        else if (v[p3] * 3 <= v[p2] * 2 && v[p3] * 3 <= v[p5] * 5)
        {
            if (!s.count(v[p3] * 3))
            {
                s.insert(v[p3] * 3);
                v[save++] = v[p3] * 3;
                p3++;
            }
            else
            {
                p3++;
            }
        }
        else if (v[p5] * 5 <= v[p2] * 2 && v[p5] * 5 <= v[p3] * 3)
        {
            if (!s.count(v[p5] * 5))
            {
                s.insert(v[p5] * 5);
                v[save++] = v[p5] * 5;
                p5++;
            }
            else
            {
                p5++;
            }
        }
    }

    cout << "The 1500'th ugly number is " << v[1500] << "." << endl;

    return 0;
}
```
