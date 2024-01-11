# Parity


[題目連結](https://onlinejudge.org/external/109/10931.pdf)



#### 解題

==>轉二進位
==>算1的數量

#### code

![](https://pic2.zhimg.com/v2-13969af71bb98e7b94289c6f15dfe7b5_b.gif)  


```cpp
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

vector<ll> binary_board(40);

void make_binary_board()
{
    binary_board[0] = 0;
    binary_board[1] = 1;
    for (int i = 2; i < 40; i++)
    {
        binary_board[i] = 2 * binary_board[i - 1];
    }
}

int main(int argc, char const *argv[])
{
    ll n;
    make_binary_board();
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        int tem = n;
        vector<int> v;
        v.clear();
        int flag = 0;
        for (int i = 39; i > 0; i--)
        {
            if (n >= binary_board[i])
            {
                n = n - binary_board[i];
                flag = 1;
                v.push_back(1);
            }
            else if (flag == 1)
            {
                v.push_back(0);
            }
        }
        ll ans = 0;
        cout << "The parity of ";
        for (const int &it : v)
        {
            cout << it;
            if (it == 1)
            {
                ans++;
            }
        }
        v.clear();
        cout << " is " << ans << " (mod 2)." << endl;
    }
    return 0;
}
```
