# Anji's Binary Tree

* 目前還在建置


## code 

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
//*題目: Anji's Binary Tree
//*解題者:神李凌華的狗
   題目來源:codeforce
   題目連結:https://codeforces.com/contest/1900/problem/C?fbclid=IwAR2E4lZI2IF7PFjhADz8695KVJI-IGyajyy2ze9ebFU54E7tyoYRzl8qcBo
   解題連結:
//*備註:昨天太累了，直接睡死了
*/

// 用遞回便利整個樹
int dfs(const vector<int> &l, const vector<int> &r, const string &s, int u)
{
    //遞迴終止條件
    if (u == 0)
        return s.size() - 1;// 如果當前節點不存在，返回 s 字串的大小減 1
    if (l[u] == 0 && r[u] == 0)
        return 0;// 如果當前節點是葉節點，返回 0
    // 返回左右子節點中選擇最小值，加上是否需要移動的操作數 
    return min(dfs(l, r, s, l[u]) + (s[u] != 'L'), dfs(l, r, s, r[u]) + (s[u] != 'R'));
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        //讓字串 s 的索引與二叉樹的節點索引相對應。
        s = ' ' + s;
        vector<int> l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i];
        }
        cout << dfs(l, r, s, 1) << endl;
    }
    return 0;
}
```
