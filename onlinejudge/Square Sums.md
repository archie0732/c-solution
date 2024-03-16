# Square Sums 

[題目連結](https://vjudge.net/problem/UVA-11470)

#### 注意 只剩一格時的狀況!!!!

#### code 


```cpp

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int caseNumber = 1;
    int n;
    while (cin >> n && n)
    {
        vector<vector<int>> board(n, vector<int>(n));

        // 读取矩阵数据
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }



        // 输出 "Case X: "
        cout << "Case " << caseNumber++ << ":";

        // 输出 sum
        int turn = 0;
        while (!board.empty())
        {
            cout << " ";
            int sum = 0;
            if (board.size() > 1)
            {
                for (int i = 0; i < board[0].size(); i++)
                {
                    sum += board[0][i];
                    sum += board[board.size() - 1][i];
                }

                board.erase(board.begin());
                board.erase(board.begin() + board.size() - 1);



                for (int i = 0; i < board.size(); i++)
                {
                    sum += board[i][0];
                    board[i].erase(board[i].begin());
                    sum += board[i].back();
                    board[i].erase(board[i].begin() + board[i].size() - 1);
                }
            }
            else
            {
                sum = board[0][0];
                cout << sum;
                break;
            }

            //debug
            /*cout << endl;
            for (int i = 0;i < board.size();i++)
            {
                for (int j = 0;j < board[i].size();j++)
                {
                    cout << board[i][j];
                }
                cout << endl;
            }
            cout << endl;*/

            cout << sum;
        }

        cout << endl; // 换行
    }
    return 0;
}
```
