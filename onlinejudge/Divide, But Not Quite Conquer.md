# Divide, But Not Quite Conquer

最近想說把CPE的一星題給補完，然後就沒什麼時間寫其他的題目與打文章了XD

[題目連結](https://onlinejudge.org/external/101/10190.pdf)


#### 解題

雖然這也是CPE 一星題，但寫完後看了一下網路上有人的code只跑得過zerojudge跑online judge 會超，所以還是來寫一篇

1. n 與 m 可能會會給 0
2. 如果真的還是會超時，可以把`cout`換成`printf`

#### code

```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n <= 1 || m <= 1)
        {
            cout << "Boring!" << endl;
            continue;
        }

        vector<int> ans;
        for (int i = n; i == 1 || (i > 1 && i % m == 0); i /= m)
        {
            ans.push_back(i);
        }

        int sequenceSize = ans.size();
        if (sequenceSize == 0 || ans[sequenceSize - 1] != 1)
        {
            cout << "Boring!" << endl;
            continue;
        }

        for (int i = 0; i < sequenceSize; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
