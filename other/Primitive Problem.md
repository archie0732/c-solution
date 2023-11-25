# Primitive Problem
```cpp
#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

#define ll long long int

vector<ll> fact;

ll power(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll tem = power(a, b >> 1, mod) % mod;
    tem = (tem * tem) % mod;
    if (b & 1)
        tem = tem * a % mod;
    return tem;
}

ll Ans(ll n)
{
    ll result = n;
    for (ll p = 2; p * p <= n; ++p)
    {

        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void solution(ll n)
{
    ll num = n - 1;
    for (ll i = 2; i * i <= num; i++)
    { // O(n)
        if (num % i == 0)
            fact.push_back(i);
        while (num % i == 0)
            num /= i;
    }
    if (num > 2)
        fact.push_back(num);
}
void solution2(ll n)
{
    ll modenum;
    for (ll i = 2; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < fact.size(); j++)
        {
            if (power(i, n / fact[j], n) == 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            modenum = i;
            break;
        }
    }
    cout << modenum << " ";
}

int main()

{
    ll p;
    cin >> p;
    solution(p);
    solution2(p);
    cout << Ans(p - 1) << endl;
}
```
