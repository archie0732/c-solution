# Prime Cuts 


[題目連結]()



* 建立質數表，接下來舊案題目說的取值、輸出就行了


![](https://pixiv.cat/81618055-2.jpg)


#### code

```cpp


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{

    vector<int>board(1001);

    // 建表
    for (int i = 0;i < 1001;i++)
    {
        board[i] = i;
    }

    for (int i = 2;i <= 1000;i++)
    {
        for (int j = 0;j < board.size();j++)
        {
            if (board[j] % i == 0 && board[j] != i)
            {
                board[j] = -1;
            }
        }
    }





    //main

    int N, C;

    while (cin >> N >> C)
    {
        vector<int>tem;

        for (int i = 1;i <= N;i++)
        {
            if (board[i] != -1)tem.push_back(board[i]);
        }


        int pn = tem.size() % 2 == 0 ? 2 * C : 2 * C - 1;

        vector<int>ans;

        for (int i = 0;i < pn;i++)
        {
            ans.push_back(tem[tem.size() / 2]);
            tem.erase(tem.begin() + tem.size() / 2);
            if (tem.empty())break;
        }

        sort(ans.begin(), ans.end());
        //output
        cout << N << " " << C << ":";


        for (const int it : ans)
        {
            cout << " ";
            cout << it;

        }
        cout << endl << endl;


    }

    return 0;
}
```
