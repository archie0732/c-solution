# Pig-Latin

[題目連結](https://vjudge.net/problem/UVA-492)



#### 解題

* 根據題目意思
* 當遇到一個單字
  >如果第一個字母是母音(不管大小寫）==> 後面加ay  
  >如果不是 ==> 第一個字母改放到字尾，後面加ay

* 如果不是單字，就用原型態輸出


![](https://i.pixiv.cat/img-original/img/2024/03/02/00/03/45/116535866_p0.jpg)


```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    // find the first charater in "aeiou" or capital
    string board = "aeiouAEIOU";

    // include ' '
    while (getline(cin, s))
    {

        for (int i = 0, back; i < s.size(); i++)
        {
            // is a letter
            if (isalpha(s[i]))
            {
                back = i + 1;
                // util meet ' '
                while (back < s.size() && isalpha(s[back]))
                    back++;
                // find a e i o u or thier capital
                if (board.find(s[i]) == -1)
                    /*
                     * let a in s
                     *  a[0] != a e i o u or capital letter
                     *  a.end.append("ay")
                     *  a[0]=> a.end.append
                     */
                    cout << s.substr(i + 1, back - i - 1) << s[i] << "ay";
                else
                    // end.append("ay")
                    cout << s.substr(i, back - i) << "ay";
                // point i move to back
                i = back - 1;
            }
            // if the s[i] isnot a letter
            else
            {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}
```


