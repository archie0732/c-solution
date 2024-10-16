#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> v(n, 0);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        if (n <= 2)
        {
            cout << "-1" << endl;
            continue;
        }

        sort(v.begin(), v.end());

        ll goal = v[n / 2];
        ll l = -1, r = 1000000000000000;
        ll ans = 0;
        while (l <= r)
        {
            ll mid = (l + r) / 2ll;
            if (2ll * goal <= (sum + mid) / n)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans + 1 << endl;
    }
}

// 1 2 3 4