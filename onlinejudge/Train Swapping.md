# Train Swapping!

[題目連結](https://vjudge.net/problem/UVA-10062)



#### 解題

* 一次只能交換兩個車廂(且要相鄰)

* 想到泡沫排序，結束

#### code 

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main(int argc, char const* argv[])
{
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++) {
      cin >> v[i];
    }
    int ans = 0;
    for (int i = 0;i < n - 1;i++) {
      for (int j = 0;j < n - 1;j++) {
        if (v[j] > v[j + 1]) {
          int tem = v[j];
          v[j] = v[j + 1];
          v[j + 1] = tem;
          ans++;
        }
      }
    }
    cout << "Optimal train swapping takes " << ans << " swaps." << endl;
  }
  return 0;
}
```
