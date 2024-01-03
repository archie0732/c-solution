# Common Permutation

[題目連結](https://onlinejudge.org/external/102/10252.pdf)


#### 小細節

找到兩個陣列相同的字元(一對一，不可一對多，相同字元可重複)  

**要排列!!!**

```
例子1

abc  
aac  

相同的字原組成的字串為:    
ac   
```

```
例子2

hcckl
ajckcl

相同的字元組成的字串為:
cckl
```
#### 解題
1. 首先，先找相同的字，遍歷迴圈
2. 找到相同字母，我為了方便直接把兩個數變成'+'跟'-'
   >一般來說，都會直接刪掉，但這樣會影響遍歷(一個人喜好)
3. 排序
4. 輸出

#### code 

![](https://c-ssl.duitang.com/uploads/blog/202110/31/20211031135621_e63dd.thumb.1000_0.jpg)

```cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    while (cin >> a >> b)
    {

        vector<char> ans;
        for (int i = 0; i < a.length(); i++)
        {
            for (int j = 0; j < b.length(); j++)
            {
                if (a[i] == b[j])
                {
                    ans.push_back(a[i]);
                    a[i] = '+';
                    b[j] = '-';
                }
            }
        }
        sort(ans.begin(), ans.end());

        for (auto it : ans)
            cout << it;

        cout << endl;
    }
    return 0;
}
```

