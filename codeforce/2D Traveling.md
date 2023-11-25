# 2D Traveling
[題目連結](https://codeforces.com/problemset/problem/1869/B)
## 題目
Piggy lives on an infinite plane with the Cartesian coordinate system on it.

There are n
 cities on the plane, numbered from 1
 to n
, and the first k
 cities are defined as major cities. The coordinates of the $`i
-th`$ city are ($`x_i`$,$`y_i`$)
.

Piggy, as a well-experienced traveller, wants to have a relaxing trip after Zhongkao examination. Currently, he is in city a
, and he wants to travel to city b
 by air. You can fly between any two cities, and you can visit several cities in any order while travelling, but the final destination must be city b
.

Because of active trade between major cities, it's possible to travel by plane between them for free. Formally, the price of an air ticket $`f(i,j)`$
 between two cities i and j  
 is defined as follows:    
 ```math
f(i,j)
\begin{cases}
  & 0,   \qquad \qquad \qquad \qquad \text{                 if cities  i  and j are both major cities }      \\
  & \text{ | }x_i - x_j| + |y_i- y_j |, \quad \text{otherwise}
\end{cases}
   
```
Piggy doesn't want to save time, but he wants to save money. So you need to tell him the **minimum** value of the total cost of all air tickets if he can take any number of flights.

### code 
![](https://github.com/archie0732/c-solution/blob/main/picture/pekora002.jpg)
```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

ll distance(ll x1, ll x2, ll y1, ll y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(int argc, char const *argv[])
{

    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n, m, s, f;
        cin >> n >> m >> s >> f;

        vector<pair<int, int>> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        ll d;

        d = distance(v[s].first, v[f].first, v[s].second, v[f].second);

        ll ans[2];
        ans[0] = 1000000000000;
        ans[1] = 1000000000000;
        for (int i = 1; i <= m; i++)
        {
            ans[0] = min(ans[0], distance(v[i].first, v[s].first, v[i].second, v[s].second));
            ans[1] = min(ans[1], distance(v[i].first, v[f].first, v[i].second, v[f].second));
        }
        ans[0] = min(ans[0] + ans[1], d);
        cout << ans[0] << endl;
    }
    return 0;
}
```
