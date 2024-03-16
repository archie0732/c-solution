#include<iostream>

//https://vjudge.net/problem/UVA-11313

using namespace std;


int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        int ans = 0;
        cin >> n >> m;
        while (n > 1)
        {
            n = n - m + 1;
            ans++;
        }
        if (n != 1)cout << "cannot do this" << endl;
        else cout << ans << endl;
    }

    return 0;
}
