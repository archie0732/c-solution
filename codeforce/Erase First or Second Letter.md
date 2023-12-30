# Erase First or Second Letter

[題目連結](https://codeforces.com/contest/1917/problem/B)

#### 解題

用set的原理

>insert的元素如果存在 ==> 不會插入(size不變)
>insert的元素如果不存在 ==> 插入(size+1)

條件

只能刪除左邊的第一個或第二個
當有兩個相同的字時的組合(舉例 : aaa)
aaa aa a ==>也就是 有 n 個相同的字，組合的種類就是 n 個

當有不同的字的組合(舉例 : abc)
a b c ab ac bc ==>6個，即 1 + 2 + 3


#### code 
![](https://pic2.zhimg.com/v2-98f4f779d231fe282858c09fd2750a7d_r.jpg)
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        set<char> check;
        string s;
        cin >> s;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            check.insert(s[i]);
            ans = check.size() + ans;
        }
        cout << ans << endl;
    }
    return 0;
}
```
