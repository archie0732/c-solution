# Vito's Family

## 題目
The world-known gangster Vito Deadstone is moving to New York. He has a very big family there, all
of them living in Lamafia Avenue. Since he will visit all his relatives very often, he is trying to find a
house close to them.  
Vito wants to minimize the total distance to all of them and has blackmailed you to write a program
that solves his problem  

* $`\textcolor{blue}{input}`$

The input consists of several test cases. The first line contains the number of test cases.
For each test case you will be given the integer number of relatives r (0 < r < 500) and the
street numbers (also integers) $`s_1, s_2, . . . , s_i, . . . , s_r `$  
where they live (0 < $`s_i`$ < 30000 ). Note that several
relatives could live in the same street number.  

* $`\textcolor{blue}{output}`$

For each test case your program must write the $`\textcolor{red}{minimal \ sum \  of \ distances \  from \  the\  optimal\  Vito’s\  house \ 
to\  each\  one\  of\  his\  relatives}`$.    
The distance between two street numbers si and $`s_j  \,is\, d_i = |s_i − s_j |`$.




### code
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 2 2 3 4
// 2 ==> 0+1+2=3
// 3 ==> 0+1+1+1=3
// 4 ==> 2+2+1=5
// 選最多的獲勝
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

                int ans = 0;
        // 中位數
        for (int i = 0; i < n; i++)
        {
            ans += abs(a[i] - a[n / 2]);
        }
        cout << ans << endl;
    }
    return 0;
}

```
