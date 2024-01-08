# Symmetric Matrix

[題目連結](https://onlinejudge.org/external/113/11349.pdf)


* 找是不是對稱矩陣(由中心點來鏡射)
* 不可以是負的

#### 解題
```
a1 a2 a3
b1 b2 b3
c1 c2 c3
```

只要比較陣列的一半就好

如下圖從a1開始(與c3比)

```
a1 x  x
x  x  x
x  x  c3
```

再來是b2 與 b3

```
x  x  x
b1 x  b3
x  x  x
```

最後是c1 與 a3

```
x  x  a3
x  x  x
c1 x  x
```

#### code 

![](https://a-static.besthdwallpaper.com/genshin-impact-blue-eyed-kamisato-ayaka-wallpaper-2000x1333-116421_39.jpg)  

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int t, count = 1;
    cin >> t;
    while (t--)
    {

        int n;
        char s;
        cin >> s >> s >> n;
        int flag = 0;
        vector<vector<ll>> matrix(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] < 0)
                {
                    flag = 1;
                }
            }
        }
        int mid = n / 2 - 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= mid; j++)
            {
                if (matrix[i][j] != matrix[n - i - 1][n - j - 1])
                {
                    flag = 1;
                    break;
                }
            }
        }
        cout << "Test #" << count << ": ";
        count++;
        if (flag == 0)
        {
            cout << "Symmetric." << endl;
        }
        else
        {
            cout << "Non-symmetric." << endl;
        }
    }
    return 0;
}
```
