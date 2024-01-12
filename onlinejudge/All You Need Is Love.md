# All You Need Is Love


[題目連結](https://onlinejudge.org/external/101/10193.pdf)  



#### 解題

求兩個數的最大公因數，使用輾轉相除法



#### code 


```cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

ll GDB(ll a, ll b)
{
    return b == 0 ? a : GDB(b, a % b);
}
int main(int argc, char const *argv[])
{
    int t, count = 1;
    cin >> t;
    while (t--)
    {
        string S, N;
        cin >> S >> N;
        ll s1 = stoi(S, 0, 2);
        ll s2 = stoi(N, 0, 2);
        vector<ll> cmp1, cmp2;

        int flag = GDB(s1, s2);

        if (flag == 1)
        {
            cout << "Pair #" << count << ": Love is not all you need!" << endl;
        }
        else
        {
            cout << "Pair #" << count << ": All you need is love!" << endl;
        }
        count++;
    }
    return 0;
}
```
