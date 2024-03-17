# Count on Cantor


[題目連結](https://vjudge.net/problem/UVA-264)


* 建表，但要注意題目方向的走向(會先由上往下，在由下往上，無限循環)

#### code


![](https://www.pixiv.cat/1166680630.jpg)


```cpp
#include<iostream>
#include<vector>

#define ll long long 



using namespace std;

void make_board(vector<pair<ll, ll>>& bt)
{
    bt[0] = { 0,0 };
    bt[1] = { 1,1 };
    int flag = 2;

    for (int i = 2;i <= 100000000;i++)
    {
        if (flag > 1 && bt[i - 1].first == 1)
        {
            bt[i] = { 1,bt[i - 1].first + bt[i - 1].second };
            flag *= -1;
        }
        else if (flag < 1 && bt[i - 1].second == 1)
        {
            bt[i] = { bt[i - 1].first + bt[i - 1].second,1 };
            flag *= -1;
        }
        else
        {
            if (flag < 1)
            {
                bt[i] = { bt[i - 1].first + 1,bt[i - 1].second - 1 };
            }
            else
            {
                bt[i] = { bt[i - 1].first - 1,bt[i - 1].second + 1 };
            }
        }
    }
}


int main()
{                             //9999689
    vector < pair<ll, ll>>board(100000002);
    make_board(board);

    ll n;
    while (cin >> n)
    {
        cout << "TERM " << n << " IS " << board[n].first << "/" << board[n].second << endl;
    }


}
```
