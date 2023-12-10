# Anji's Binary Tree

[題目連結](https://codeforces.com/contest/1900/problem/C)
### 題目
Keksic keeps getting left on seen by Anji. Through a mutual friend, he's figured out that Anji really likes binary trees and decided to solve her problem in order to get her attention.

Anji has given Keksic a binary tree with n
 vertices. Vertex 1
 is the root and does not have a parent. All other vertices have exactly one parent. Each vertex can have up to 2
 children, a left child, and a right child. For each vertex, Anji tells Keksic index of both its left and its right child or tells him that they do not exist.

Additionally, each of the vertices has a letter si
 on it, which is either 'U', 'L' or 'R'.

Keksic begins his journey on the root, and in each move he does the following:

* If the letter on his current vertex is 'U', he moves to its parent. If it doesn't exist, he does nothing.  
* If the letter on his current vertex is 'L', he moves to its left child. If it doesn't exist, he does nothing.  
* If the letter on his current vertex is 'R', he moves to its right child. If it doesn't exist, he does nothing.


Before his journey, he can perform the following operations: choose any node, and replace the letter written on it with another one.
You are interested in the minimal number of operations he needs to do before his journey, such that when he starts his journey, he will reach a leaf at some point. A leaf is a vertex that has no children. It does not matter which leaf he reaches. Note that it does not matter whether he will stay in the leaf, he just needs to move to it. Additionally, note that it does not matter how many times he needs to move before reaching a leaf.

Help Keksic solve Anji's tree so that he can win her heart, and make her come to Čačak.

## 解題

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
