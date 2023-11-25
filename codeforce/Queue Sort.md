# Queue Sort
[題目連結](https://codeforces.com/problemset/problem/1899/E)
### 題目
Vlad found an array a
 of n
 integers and decided to sort it in non-decreasing order.

To do this, Vlad can apply the following operation any number of times:

1. $`\textcolor{blue}{Extract\, the\, first\, element}`$ of the array and insert it at the $`\textcolor{red}{end}`$;
2. **Swap** that element with the $`\textcolor{red}{previous\, one\, until\, it\, becomes\, the\, first\, or\, until\, it\, becomes\, strictly\, greater\, than\, the\, previous\, one}`$.

Note that both actions are part of the operation, and for one operation, you must apply both actions.

For example, if you apply the operation to the array [4,3,1,2,6,4
], it will change as follows:

* [$`\textcolor{red}{4}`$,3,1,2,6,4];  
* [3,1,2,6,4,$`\textcolor{red}{4}`$];  
* [3,1,2,6,$`\textcolor{red}{4}`$,4];  
* [3,1,2,$`\textcolor{red}{4}`$,6,4].


Vlad doesn't have time to perform all the operations, so he asks you to determine the minimum number of operations required to sort the array or report that it is impossible.

Input
The first line of the input contains a single integer t
 (1≤t≤$`10^4`$
) — the number of test cases. Descriptions of the test cases follow.

The first line of each test case contains a single integer n
 (1≤n≤$`2⋅10^5`$
) — the length of the array.

The second line of each test case contains n
 integers $`a_1,a_2,a_3,…,a_n`$
 (1≤$`a_i`$≤$`10^9`$
) — the elements of the array.

It is guaranteed that the sum of n
 over all testcases does **not exceed $`2*10^5`$**
.


### code
```cpp
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] <= a[j])
        {
            j = i;
        }
    }
    for (int i = j + 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            cout << "-1"<<endl;
            return;
        }
    }
    cout << j << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```
