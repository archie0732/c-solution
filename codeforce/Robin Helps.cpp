#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int ans = 0, has = 0;

        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;

            if (p >= k)
            {
                has += p;
            }
            else if (p == 0 && has >= 1)
            {
                ans++;
                has--;
            }
        }

        cout << ans << endl;
    }
    return 0;
}