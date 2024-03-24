# The book thief

[題目連結](https://vjudge.net/problem/Uva-12908)



* `upper_bound` YYDS!!!!
* `it` 指的是目標值的第一個大於n值的位置，`*it`就是指標取值



```cpp
#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{

    vector<ll>board(1000001, 0);
    for (int i = 1;i < 1000001;i++)
    {
        board[i] = board[i - 1] + i;
    }
    ll n;

    while (cin >> n && n)
    {
        ll page, all;
        auto it = upper_bound(board.begin(), board.end(), n);
        all = it - board.begin();
        page = *it;

        cout << page - n << " " << all << endl;
    }

    return 0;
}

// 4 1+2+3 = 6
```
