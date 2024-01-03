# Summing Digits

[題目連結](https://onlinejudge.org/external/113/11332.pdf)  


#### 解題

1. [分解數字]()
2. 把拆解數字假起來
   >如果 >=10 ==> 回到第一步
   >否則 ==> 結束

#### code 

![](https://th.bing.com/th/id/R.6bca5b9e8b8bb385f10194604964fe6e?rik=bErG%2b%2fDlW5rljg&pid=ImgRaw&r=0)

```cpp

#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    ll n;

    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector<ll> slice;
        ll ans = 0;
        int flag = 1;
        for (int i = 0; flag != 0; i++)
        {
            ans += n % 10;
            n = n / 10;
            if (n == 0)
            {
                if (ans < 10)
                    flag = 0;
                else
                {
                    n = ans;
                    ans = 0;
                }
            }
        }
        for (int i = 0; i < slice.size(); i++)
            cout << slice[i] << " ";

        cout << ans << endl;
    }
    return 0;
}
```
