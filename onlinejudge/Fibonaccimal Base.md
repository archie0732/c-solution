# Fibonaccimal Base

[題目連結](https://onlinejudge.org/external/9/948.pdf)


#### 解題

1. 建(費波納器)數列表 ==> 1=1 2=2 3=1+2 4=2+3 (左邊代表在第幾個位元 ; 右邊代表十進位)
2. 從大的往下減
>遇到第一個<=目標值時才開始
>遇到比她小 填 1
>遇到比他大 填 0


#### code 

![](https://xinzhuobu.com/wp-content/uploads/2022/07/20220801002.jpg)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board(40);

void make_fib_board()
{
    board[0] = 0;
    board[1] = 1;
    board[2] = 1;
    for (int i = 2; i <= 39; i++)
    {
        board[i] = board[i - 1] + board[i - 2];
    }
    // reverse(board.begin(), board.end());
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    make_fib_board();
    while (t--)
    {

        int n, tem;
        vector<int> ans;
        cin >> n;
        tem = n;
        int flag = 0;
        for (int i = 39; i > 1; i--)
        {
            if (n >= board[i])
            {
                n = n - board[i];
                flag = 1;
                ans.push_back(1);
            }
            else if (flag == 1)
            {
                ans.push_back(0);
            }
        }
        // reverse(ans.begin(), ans.end());
        cout << tem << " "
             << "= ";
        for (int it : ans)
        {
            cout << it;
        }
        cout << " (fib)" << endl;
    }

    return 0;
}
```
