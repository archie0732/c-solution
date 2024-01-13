#  Simply Emirp

[ Simply Emirp](https://onlinejudge.org/external/102/10235.pdf)


#### 解題

因為因數是會對稱的==>所以只要遍歷數的一半(開根號)
>如果只有一個根( 1 ) ==> 質數  
>有兩個根以上(所有根=*2) => 不是

接下來在去把數字相反

$` \textcolor{red}{!!注意!!} `$  

如果數字相反與相反前相同，那就是同一個數字 ==> 不是`Emirp`


#### code 

![](https://th.bing.com/th/id/R.1db70f35e7f3fc0b97807b6d6740ea97?rik=iv6c0dyhAZaPwA&pid=ImgRaw&r=0)
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

ll di_count(ll n)
{
    vector<ll> num;
    ll x = sqrt(n);
    for (ll i = 1; i <= x; i++)
    {
        if (n % i == 0)
            num.push_back(i);
        if (num.size() > 2)
            return 3;
    }
    return num.size();
}

int main(int argc, char const *argv[])
{
    string a;
    while (cin >> a)
    {
        ll x = stoi(a);
        string s = a;
        int ans = di_count(x);
        int ans_2 = 0;
        if (ans == 1)
        {
            reverse(a.begin(), a.end());
            if (a == s)
            {
                ans_2 = 0;
            }
            else
            {
                ll c = stoi(a);
                ans_2 = di_count(c);
            }
        }
        if (ans_2 == 1)
        {
            cout << s << " is emirp." << endl;
        }
        else if (ans == 1)
        {
            cout << s << " is prime." << endl;
        }
        else
        {
            cout << s << " is not prime." << endl;
        }
    }
    return 0;
}
```
