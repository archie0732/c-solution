# Polynomial Showdown

### 題目連結
[點我進入](https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/392.pdf)


### 解題
1. 只是普通的條件，有幾點要注意
   >1. 第一個數字是負數要將**負號與數字貼在一起**不可分開或不輸出  
   >2. -1是開頭的也要關照一下  
   >3. 整串數字只有一個零0也要注意  

2. 也可以用`cin.eof()`來判斷要不要結束


#### code 
```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;
/*
    題目:Polynomial Showdown
    題目連結:https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/392.pdf
    
    解題者:神里綾華的狗
*/


//會重複，故使用含式
void printx(int x, int i)
{
    if (i == 0)
    {
        cout << x;
    }
    else if (x == 1)
    {
        cout << "x";
    }
    else
    {
        cout << x << "x";
    }

    if (i > 1)
    {
        cout << "^" << i;
    }
}

int main(int argc, char const *argv[])
{

    while (true)
    {
        int x;
        int flag = 0;
        //數字
        queue<int> q;
        //位數
        queue<int> count;
        for (int i = 1; i < 10; i++)
        {
            if (cin >> x)
            {
                if (x != 0)
                {
                    q.push(x);
                    count.push(9 - i);
                }
            }
            //efo 結束
            else
            {
                return 0;
            }
        }
        //以防輸入只有一個0
        if (q.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        //第一位是負數
        if (q.front() < 0)
            cout << "-";

        //印出第一位
        printx(abs(q.front()), count.front());
        q.pop();
        count.pop();

        //從第二位開始印
        while (!q.empty())
        {
            if (q.front() > 0)
            {
                cout << " + ";
                printx(q.front(), count.front());
            }
            else if (q.front() < 0)
            {
                cout << " - ";

                printx(abs(q.front()), count.front());
            }
            q.pop();
            count.pop();
        }

        cout << endl;
    }

    return 0;
}
```
