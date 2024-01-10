# Funny Encryption Method


[題目連結](https://onlinejudge.org/external/100/10019.pdf)



~~ 我有病把進位算算直接寫出來，也可以直接調函示庫喔~~

#### 解題

1. 把 10 進位轉 2 進位
2. 把 16 進位轉 2 進位
 >先[拆分數字]()    
>再用二進位轉法  

[進位轉換法(建表)]()

3. 算 1的數量
4. Happy_END


#### code

![](https://th.bing.com/th/id/OIP.8uCeJpTePgER4PBqdPuBhAHaHa?rs=1&pid=ImgDetMain)

```cpp
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#define ll long long

using namespace std;

vector<ll> binary(40);

// 1 2 4 8 16
void make_binary_board()
{
    binary[0] = 0;
    binary[1] = 1;
    for (int i = 2; i < 40; i++)
    {
        binary[i] = binary[i - 1] * 2;
    }
}

// 256 ==> 6 5 2 // 256 ==> 0010 0101 0110

// 1 2 4 8 ||16

vector<int> hex_binary;
vector<int> dec_binary;

void decimal_to_binary(int c)
{
    int flag = 0;
    dec_binary.clear();
    for (int i = 39; i > 0; i--)
    {
        if (c >= binary[i])
        {
            c = c - binary[i];
            flag = 1;
            dec_binary.push_back(1);
        }
        else if (flag == 1)
        {
            dec_binary.push_back(0);
        }
    }
}

void hex_to_binary(int a)
{

    vector<int> split;
    while (a > 0)
    {
        split.push_back(a % 10);
        a = a / 10;
    }
    reverse(split.begin(), split.end());
    hex_binary.clear();
    while (split.size() > 0)
    {
        // cout << split.front() << endl;

        for (int i = 4; i > 0; i--)
        {
            if (split.front() >= binary[i])
            {
                split.front() = split.front() - binary[i];
                hex_binary.push_back(1);
            }
            else
            {
                hex_binary.push_back(0);
            }
        }
        split.erase(split.begin() + 0);
    }
}

pair<int, int> count_1()
{
    pair<int, int> count;
    while (dec_binary.size() > 0)
    {
        if (dec_binary.back() == 1)
        {
            count.first++;
        }
        dec_binary.pop_back();
    }

    while (hex_binary.size() > 0)
    {
        if (hex_binary.back() == 1)
        {
            count.second++;
        }
        hex_binary.pop_back();
    }
    return make_pair(count.first, count.second);
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        hex_binary.clear();
        binary.clear();
        make_binary_board();
        decimal_to_binary(n);
        /*for (int it : dec_binary)
        {
            cout << it;
        }
        cout << endl;*/

        hex_to_binary(n);
        /*for (int it : hex_binary)
        {
            cout << it;
        }
        cout << endl;*/
        pair<int, int> ans = count_1();
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
```
