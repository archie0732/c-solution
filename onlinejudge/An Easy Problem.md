# An Easy Problem!

[題目連結](https://onlinejudge.org/external/100/10093.pdf)

~~根本不簡單，一大堆陷阱而且測值還沒跟你說~~  


#### 解題

將`0~9` `A~Z` `a~z` 做成表格，去查表找位置(這樣可以避免遇到一些奇怪的測值像是+與空格)  

base 就是從哪裡開始往上去找`N`
>再找字元時，用到最大的就是從他開始(如果遇到A，就是從時開始，因為0~9進位弄不出A==>溢位)
> N 進位數字即 $`{a_0}*n^{n-1}+{a_1}*n^{n-2}.....{a_{n-1}}*n^{1}+a_n`$  
>是可以被$`a_n*a_{n-1}*.....*a_{0}`$ 整除
>
>換句話說把其拆分相加==>再去被除==>也同樣是N base 的答案

* 注意:測值會有一行字(有可能會跟要得不同)EX: `   +13A5`
* 如果base 超過 62 就要輸出`such number is impossible!`

![](https://th.bing.com/th/id/OIP.rz4_rxXpwyl6NZbXAO8vSAHaKe?rs=1&pid=ImgDetMain)


#### code 

* 2024/03/25 新版

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;

    while (getline(cin, s))
    {
        int max_base = 0, sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int tem = 0;
            if (s[i] >= '0' && s[i] <= '9')
            {
                tem = s[i] - '0';
                sum += tem;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                tem = s[i] - 'A' + 10;
                sum += tem;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                tem = s[i] - 'a' + 36;
                sum += tem;
            }
            else
                continue;

            max_base = max(max_base, tem);
        }
        // cout << "sum: " << sum << " max_base " << max_base << endl;
        if (sum == 0)
            cout << 2 << endl;
        else
        {
            for (int i = max_base; i <= 62; i++)
            {
                if (i == 62)
                {
                    cout << "such number is impossible!" << endl;
                    break;
                }
                else if (sum % i == 0)
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
}
```

* 舊版

```cpp

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const string board = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

int main(int argc, char const *argv[])
{
    string s;
    while (getline(cin, s))
    {
        bool flag = 0;
        int ans;
        int base = 1, sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            auto it = find(board.begin(), board.end(), s[i]);
            if (it != board.end())
            {
                int side = distance(board.begin(), it);
                // cout << side << endl;
                if (base < side)
                    base = side;
                sum = side + sum;
                // cout << "base:" << base << endl;
            }
        }
        // cout << sum << endl;
        for (int i = base; i <= 62; i++)
        {
            if (sum % i == 0)
            {
                cout << i + 1 << endl;
                break;
            }
            if (i == 62)
            {
                cout << "such number is impossible!" << endl;
                break;
            }
        }
    }

    return 0;
}
```
