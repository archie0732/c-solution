# Berland Crossword
```cpp
#include <iostream>
using namespace std;
int main()
{

    int t = 1;
    std::cin >> t;
    while (t--)
    {
        int n, i, j = 0, u, d, l, r;
        cin >> n >> u >> r >> d >> l;
        int uu = u, ll = l, rr = r, dd = d;
        if (u <= n - 2 && d <= n - 2 && l <= n - 2 && r <= n - 2)
        {
            cout << "YES"<<endl;
            continue;
        }
        if (u == n - 1)
        {
            u--;
            if (l > r)
                l--;
            else
                r--;
        }
        else if (u == n)
        {
            u--;
            u--;
            l--;
            r--;
        }
        if (d == n - 1)
        {
            d--;
            if (l > r)
                l--;
            else
                r--;
        }
        else if (d == n)
        {
            d--;
            d--;
            l--;
            r--;
        }
        if (l < 0 || r < 0)
        {
            cout << "NO"<<endl;
            continue;
        }
        if (ll == n - 1)
        {
            ll--;
            if (uu > dd)
                uu--;
            else
                dd--;
        }
        else if (ll == n)
        {
            ll--;
            ll--;
            uu--;
            dd--;
        }
        if (rr == n - 1)
        {
            rr--;
            if (uu > dd)
                uu--;
            else
                dd--;
        }
        else if (rr == n)
        {
            rr--;
            rr--;
            uu--;
            dd--;
        }
        if (uu < 0 || dd < 0)
        {
            cout << "NO"<<endl;
            continue;
        }
        cout << "YES"<<endl;
    }
}
```
