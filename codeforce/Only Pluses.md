# Only Pluses


[連結](https://codeforces.com/contest/1992/problem/A)


* 看得懂英文就會ㄅ

#### code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    vector<int> a(3, 0);
    cin >> a[0] >> a[1] >> a[2];

    for (int i = 0; i < 5; i++) {
      sort(a.begin(), a.end());
      a[0]++;
    }
    long long ans = a[0] * a[1] * a[2];

    cout << ans << endl;
  }

  return 0;
}
```
