# Hardwood Species

[題目連結](https://vjudge.net/problem/UVA-10226)


#### 解題

* 算樹木的種類占比


**解法**  

* 用`map`
* 算總共的數量後就可以算比值與%數了

**陷阱**  

* 輸入`test case` 後會多空一行
* 測值(樹)完成後會在空一行(sample沒有寫)
* 注意`pretention error`

#### code 


```cpp
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
  int t;
  string tem;
  cin >> t;
  getline(cin, tem);
  getline(cin, tem);
  int turn = 0;
  while (t--) {
    if (turn > 0) {
      cout << endl;
    }
    map <string, int> count;
    string s;
    int range = 0;
    while (getline(cin, s) && s != "") {
      count[s]++;
      range++;
    }

    for (auto it : count) {
      cout << it.first << " ";
      printf("%.4f\n", double(it.second) / range * 100);
    }
    turn++;
  }
  return 0;
}
```
