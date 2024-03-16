# Cubes 

[題目連結](https://vjudge.net/problem/UVA-11428)

#### code (cpp)


```cpp
#include<iostream>
#define ll long long
using namespace std;

/*
   https://vjudge.net/problem/UVA-11428
   解題: 建表!!
   注意: 不包含0
*/
int main()
{

    ll ans_board[10001] = {};
    ll x[10001], y[10001];

    for (int i = 1;i < 60;i++)
    {
        for (int j = 1;j <= i;j++)
        {
            if (i * i * i - j * j * j < 10001 && ans_board[i * i * i - j * j * j] == 0)
            {
                ans_board[i * i * i - j * j * j] = 1;
                x[i * i * i - j * j * j] = i;
                y[i * i * i - j * j * j] = j;
            }
        }
    }

    int n;

    while (cin >> n && n)
    {
        if (ans_board[n])
        {
            cout << x[n] << " " << y[n] << endl;
        }
        else
        {
            cout << "No solution" << endl;
        }
    }

    return 0;
}
```
