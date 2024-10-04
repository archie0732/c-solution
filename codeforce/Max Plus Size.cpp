#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        int odd = 0, even = 0, flag = 0;
        for (int i = 1; i <= n; i++)
        {

            cin >> v[i];
            if (i % 2)
            {
                odd = max(v[i], odd);
                flag++;
            }
            else
            {
                even = max(even, v[i]);
            }
        }

        cout << max(flag + odd, even + (n - flag)) << endl;
    }
}