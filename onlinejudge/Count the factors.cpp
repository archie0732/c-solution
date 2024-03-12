#include<iostream>
#include<set>
#define ll long long 
//https://vjudge.net/problem/UVA-10699

using namespace std;


int main()
{

    ll n;
    while (cin >> n && n)
    {

        set<ll> ans;
        ll backup = n;

        while (n % 2 == 0)
        {
            ans.insert(2);
            n /= 2;
        }

        for (int i = 3;n > 1;i += 2)
        {
            while (n % i == 0)
            {
                ans.insert(i);
                n /= i;
            }
        }

        cout << backup << " : " << ans.size() << endl;

    }

    return 0;
}
