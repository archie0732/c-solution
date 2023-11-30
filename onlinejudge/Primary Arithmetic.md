# Primary Arithmetic
[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=976)
## 題目

Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the  
“carry” operation - in which a 1 is carried from one digit position to be added to the next - to be a  
significant challenge. Your job is to count the number of carry operations for each of a set of addition  
problems so that educators may assess their difficulty.  

$`\textcolor{blue}{input}`$

Each line of input contains two unsigned integers less than 10 digits. The last line of input contains **‘0
,0’**


$`\textcolor{blue}{output}`$  

For each line of input except the last you should compute and print the number of carry operations
that would result from adding the two numbers, in the format shown below.

#### sample 

123 456  
555 555  
123 594  
0 0  
```
No carry operation.
3 carry operations.
1 carry operation.
```

### $`\textcolor{red}{note}`$
0 要輸出No 且字尾不用加`s`  
1個沒有加`s`  
2個以上要加`s`  
### code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    while (true)
    {
        int a, b;
        int count = 0;
        cin >> a >> b;
        if (b > a)
        {
            int tem;
            tem = a;
            a = b;
            b = tem;
        }
        if (a == 0 && b == 0)
        {
            break;
        }
        vector<int> va, vb;
        while (a != 0 || b != 0)
        {
            if (a != 0)
            {
                va.push_back(a % 10);
                a = a / 10;
            }
            if (b != 0)
            {
                vb.push_back(b % 10);
                b = b / 10;
            }
        }

        for (int i = 0; i < va.size(); i++)
        {
            if (vb.size() > i)
            {
                if (va[i] + vb[i] >= 10)
                {
                    count++;
                    va[i + 1] += 1;
                }
            }
            else if (va.size() > i)
            {
                if (va[i] >= 10)
                {
                    count++;
                    va[i + 1] += 1;
                }
            }
        }
        if (count > 1)
            cout << count << " carry operations." << endl;
        else if (count == 1)
            cout << "1 carry operation." << endl;
        else
            cout << "No carry operation." << endl;
    }
    return 0;
}
```
