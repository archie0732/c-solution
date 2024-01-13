# 2 the 9s

[題目連結](https://onlinejudge.org/external/109/10922.pdf)

#### 解題

1. 只要是 9 的倍數==>所有數字相加 也可以被 9 整除
>EX:
>999 ==>9+9+9 => 27
>972 ==>9+7+2 ==> 18

至於它可以是9的幾次方的倍數，就將上面的方法再試幾次，算做了幾次就行



#### code 

![](https://i.ytimg.com/vi/j81JsKvrszM/maxresdefault.jpg)
```cpp
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int slove(string s, int count)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int tem = s[i] - '0';
        sum += tem;
    }
    if (sum % 9 != 0)
    {
        return -1;
    }
    else if (sum == 9)
    {
        return count + 1;
    }
    else
    {
        return slove(to_string(sum), ++count);
    }
}

int main()
{
    string s;
    while (1)
    {
        cin >> s;
        int sum = 0;
        int ans = 0;
        if (s == "0")
            break;

        ans = slove(s, 0);
        if (ans != -1)
        {
            cout << s << " is a multiple of 9 and has 9-degree " << ans << "." << endl;
        }
        else
        {
            cout << s << " is not a multiple of 9." << endl;
        }
    }

    return 0;
}
```
