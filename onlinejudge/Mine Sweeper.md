# Mine Sweeper 

* 大便中的大便


[題目連結](https://vjudge.net/problem/UVA-10279)



#### 解題


建一個`ans[][]`

1. 如果遇到`x`就執行以下，否則ans[i][j]='.'
2. 如果採到炸彈gg=1
3. 檢查上下左右有幾棵炸彈
4. 填入ans[i][j]裡


* **如果gg=0那麼在輸出炸彈那格時，用`*`代替.**


#### code 

![](https://i.pixiv.cat/img-original/img/2024/03/02/20/36/48/116559486_p0.png)

```cpp

#include<iostream>
#include<vector>


using namespace std;

int turn = 0;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        getchar();
        getchar();
        cin >> n;
        if (turn)cout << endl;
        char board[n][n];
        char game[n][n];

        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                cin >> board[i][j];
            }
        }
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                cin >> game[i][j];
            }
        }


        char ans[n][n];
        int gg = 0;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                int tem = 0;
                if (game[i][j] == 'x')
                {
                    if (board[i][j] == '*')gg = 1;
                    if (i - 1 >= 0 && board[i - 1][j] == '*')tem++;
                    if (j - 1 >= 0 && board[i][j - 1] == '*')tem++;
                    if (i + 1 < n && board[i + 1][j] == '*')tem++;
                    if (j + 1 < n && board[i][j + 1] == '*')tem++;
                    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == '*')tem++;
                    if (i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] == '*')tem++;
                    if (i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] == '*')tem++;
                    if (i + 1 < n && j + 1 < n && board[i + 1][j + 1] == '*')tem++;

                    ans[i][j] = ('0' + tem);
                }
                else
                {
                    ans[i][j] = '.';
                }
            }
        }

        for (int i = 0;i < n;i++)
        {
            if (i)cout << endl;
            for (int j = 0;j < n;j++)
            {
                if (board[i][j] == '*' && gg)cout << '*';
                else cout << ans[i][j];
            }

        }
        turn++;
    }

    return 0;
}
```
