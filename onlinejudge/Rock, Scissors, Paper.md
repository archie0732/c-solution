# Rock, Scissors, Paper

[題目連結](https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/10443.pdf)

#### 解題

講一下題目再講啥
新的表就是舊的領地去四周(上下左右)找，有贏他的型態就淘汰   
，其位置在新的表改變贏他的型態==>如果都平手或贏就不用變  

EX:

RSR
RRR
RPR

DAY 1:

第一個 R (第一排第一列)的四周分別為 ==> S(右)、R(下) ==>  R 沒輸過 新表的第一排第一列變成 R 

第二個 S (第二排第一列)的四周分別為 ==> R(左)、R(右)、R(下) ==> 輸給 R，新表的第二排第一列變成 R

第三個 R 與第一個一樣， R 沒輸過 新表的第三排第一列變成 R

* 換排

第一個 R (第一排第二列)的四周分別為 ==> R(上)、R(右)、R(下) ==> R 沒輸過 新表的第一排第二列變成 R

第二個 R (第二排第二列)的四周分別為 ==> S(上)、R(左)、R(右)、P(下) ==> P 贏 R 新表的第二排第二列變成 P

第三個 R 與第一個一樣， R 沒輸過 新表的第三排第二列變成 R

* 換排

同上操作

最後新表為:

RRR
RPR
PPP

至於 DAY 2 就把DAY 1當`舊表`，而 DAY 2 就是`新表`


#### code 

![](https://i.ex-cdn.com/mgn.vn/files/content/2022/08/03/kamisato-ayaka-1145.jpg)  
```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

char Whowin(char a, char b, char change)
{
    char k;
    if (a == b)
        k = a;
    else if (a == 'P' && b == 'S')
    {
        k = 'S';
    }
    else if (a == 'S' && b == 'R')
    {
        k = 'R';
    }
    else if (a == 'R' && b == 'P')
    {
        k = 'P';
    }
    else
    {
        k = a;
    }
    if (k == change || k == a)
        return change;
    else
        return k;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c, d;
        cin >> r >> c >> d;

        vector<vector<vector<char>>> updata(d + 1, vector<vector<char>>(r + 2, vector<char>(c + 2, 'X')));
        for (int n = 0; n <= d; n++)
            for (int i = 0; i < r + 2; ++i)
                for (int j = 0; j < c + 2; ++j)
                    updata[n][i][j] = 'X';

        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cin >> updata[0][i][j];
            }
        }

        for (int n = 1; n <= d; n++)
        {
            for (int i = 1; i <= r; i++)
            {
                for (int j = 1; j <= c; j++)
                {
                    char o = updata[n - 1][i][j];
                    o = Whowin(updata[n - 1][i][j], updata[n - 1][i][j + 1], o);
                    o = Whowin(updata[n - 1][i][j], updata[n - 1][i + 1][j], o);
                    o = Whowin(updata[n - 1][i][j], updata[n - 1][i][j - 1], o);
                    o = Whowin(updata[n - 1][i][j], updata[n - 1][i - 1][j], o);
                    updata[n][i][j] = o;
                }
            }
        }

        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cout << updata[d][i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
