# B2-Sequence

[題目連結](https://onlinejudge.org/external/110/11063.pdf)


#### 小細節

1. 前一個數一定要比後一個數小
2. 全部要 > 0
3. test case 之間要空兩隔


#### 解題

* 用set 如果重複就不是(包含上述小細節也會導致不是)

#### code 

![](https://th.bing.com/th/id/R.811d6e92285d5ac41da7357d14a0bfc8?rik=ELswhWEPHvtSnw&pid=ImgRaw&r=0)


```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int t, count = 1;
    while (cin >> t)
    {
        bool flag = false;
        string s;

        vector<int> v(t);
        set<int> check;

        for (int i = 0; i < t; i++)
        {
            cin >> v[i];
            if (v[i] < 1)
            {
                flag = true;
            }
            if (i != 0 && v[i - 1] >= v[i])
                flag = true;
        }

        for (int i = 0; i < t - 1; i++)
        {
            for (int j = i; j < t; j++)
            {
                int tem = v[i] + v[j];
                if (check.count(tem))
                {
                    flag = true;
                    break;
                }
                check.insert(tem);
            }

            if (flag)
                break;
        }

        cout << "Case #" << count << ": ";
        count++;
        if (!flag)
            cout << "It is a B2-Sequence." << endl
                 << endl;
        else
            cout << "It is not a B2-Sequence." << endl
                 << endl;
    }

    return 0;
}
```
