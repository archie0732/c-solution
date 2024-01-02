# Decode the Mad man


[題目連結](https://onlinejudge.org/external/102/10222.pdf)  



#### 解題

* 輸入的字元往左兩隔就是答案

1. 建表
2. 找輸入==>左移兩格==>END


#### code 

![](https://pic3.zhimg.com/v2-23763badada34f3f5903647873e9ff56_r.jpg)
```cpp
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;

    string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    while (getline(cin, s))
    {

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                cout << s[i];
            else
            {
                int a = keyboard.find(tolower(s[i]));
                cout << keyboard[a - 2];
            }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
```
