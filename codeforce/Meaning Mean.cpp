#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        int mn = 10000000000, mx = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
        }
        vector<int> mp;
        mp.push_back((mn + mx) / 2 + (mn + mx) % 2);
        mn = mp[0];
        mx = mp[0];
        while (!mp.empty())
        {
        }
    }
}