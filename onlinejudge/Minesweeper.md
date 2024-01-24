# Minesweeper

[題目連結](https://vjudge.net/problem/UVA-10189)


### 注意
如果沒有在正確的地方換行，有可能會`Presentation Error`，不可以放在最後面會多換一行而出錯!!



#### 解題

* 如果該點本身是`*`就變-1
* 找上下左右斜上斜下有`*`就+1


輸出時
* -1 輸出 `*`
* 不是-1就輸出計算的分數


#### code

![](https://rare-gallery.com/thumbnail/30452-Lumine-Genshin-Impact-Kamisato-Ayaka-Genshin-ImpactLumine.jpg)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> board(10, "0");

vector<vector<int>> scoreboard;

int a, b;

void scorecount(int i, int j)
{
    if (board[i][j] == '*')
    {
        scoreboard[i][j] = -1;
    }
    else
    {
        // 上
        if (i != 0 && board[i - 1][j] == '*')
        {
            scoreboard[i][j]++;
        }
        // 下
        if (i != a - 1 && board[i + 1][j] == '*')
        {
            scoreboard[i][j]++;
        }
        // 左
        if (j != 0 && board[i][j - 1] == '*')
        {
            scoreboard[i][j]++;
        }
        // 右
        if (j != b - 1 && board[i][j + 1] == '*')
        {
            scoreboard[i][j]++;
        }
        // 左上
        if (i != 0 && j != 0 && board[i - 1][j - 1] == '*')
        {
            scoreboard[i][j]++;
        }
        // 右下
        if (i != a - 1 && j != b - 1 && board[i + 1][j + 1] == '*')
        {
            scoreboard[i][j]++;
        }
        // 右上
        if (i != 0 && j != b - 1 && board[i - 1][j + 1] == '*')
        {
            scoreboard[i][j]++;
        }
        // 左下
        if (i != a - 1 && j != 0 && board[i + 1][j - 1] == '*')
        {
            scoreboard[i][j]++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int turn = 1;
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            break;
        }
        else if (turn > 1)
            cout << endl;
        board.assign(a, "0");
        scoreboard.assign(a, vector<int>(b, 0));
        for (int i = 0; i < a; i++)
        {
            string s;
            cin >> s;
            board[i] = s;
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                scorecount(i, j);
            }
        }
        // cout << "Field #" << turn << ":" << endl;
        printf("Field #%d:\n", turn);
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (scoreboard[i][j] == -1)
                    printf("*");
                else
                    printf("%d", scoreboard[i][j]);
            }
            cout << endl;
        }

        turn++;
    }

    return 0;
}
```
