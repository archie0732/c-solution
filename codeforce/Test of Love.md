# Test of Love

[題目連結](https://codeforces.com/contest/1992/problem/D)

```bash
1.
陸  W  L   
       ^ 跟上一塊木頭的距離 > 能跳的距離嗎，有的話只能用游的
2.
陸  W  C L <------一樣跟上塊木頭的距離有 > 能跳的距離嗎 (這次不能游)
       ^不能游泳
```

#### code

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;

  while (t--) {

    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    int pre = -1, flag = 0, u = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'C') {
        int d = i - pre;

        if (d >= m) {
          flag++;
        }
      } else if (s[i] == 'W') {
        int d = i - pre;

        if (d >= m) {
          k--;
        }
      } else {
        pre = i;
      }
    }

    if (flag || k < 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
```
