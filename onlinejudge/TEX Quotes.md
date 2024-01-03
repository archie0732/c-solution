# TEX Quotes


[題目連結](https://onlinejudge.org/external/2/272.pdf)


#### 解題

用一個計數器`count`
>當`count == 0`時把`"`變成 ` 同時在插入一個 `
>當`count == 1`時把`"`變成`'` 同時在插入一個 `'`


>當第一次遇到`"`時，`count`這時是 0 ，執行(count==0)，然後把 `count` 變成 1
>當第一次遇到`"`時，`count`這時是 0 ，執行(count==1)，然後把 `count` 變成 0
>當第三次遇到`"`時，`count`這時是 0 ，執行(count==0)，然後把 `count` 變成 1
>.....無限循環直到程式結束~


#### code 

![](https://i.pinimg.com/originals/e0/c8/9c/e0c89c19a2684c7711937d71bfc7f88d.jpg)  

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    int count1 = 0, count2 = 0;
    while (getline(cin, s))
    {

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '"' && count2 == 0)
            {
                s[i] = '`';
                s.insert(s.begin() + i, '`');
                count2 = 1;
            }
            else if (s[i] == '"' && count2 == 1)
            {
                s[i] = '\'';
                s.insert(s.begin() + i, '\'');
                count2 = 0;
            }
        }
        cout << s << endl;
    }
    return 0;
}
```
