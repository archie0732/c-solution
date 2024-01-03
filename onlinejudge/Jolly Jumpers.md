# Jolly Jumpers


[題目連結](https://onlinejudge.org/external/100/10038.pdf)  

#### 解題

1. 相鄰兩數相減，存入`vector`
2. 排序`vector`
3. 具對比是否從1排到n-1


#### code 

![](https://tsundora.com/image/2021/08/genshin_2133.jpg)

```cpp

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        vector<int> save;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i < n; i++)
        {
            int c = abs(v[i] - v[i - 1]);
            save.push_back(c);
        }
        sort(save.begin(), save.end());
        for (int i = 0; i < save.size(); i++)
        {
            if (save[i] != i + 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "Not jolly" << endl;
        else
            cout << "Jolly" << endl;
    }

    return 0;
}
```
