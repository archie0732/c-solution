#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        /*
            k^? < n + (n - k^n)

            k ^ x = n
        */
        int ans = 0;
        while (n > 0 && k > 1)
        {
            ans += n % k;
            n /= k;
        }
        cout << (k == 1 ? n : ans) << endl;
    }
}