# Eb Alto Saxophone Player

[題目連結](https://vjudge.net/problem/UVA-10415)



#### 解題

* 建表，查表，如果有段開就計數，結束
* 注意`Presentation error`(空格)


#### code

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;



int main(int argc, char const* argv[])
{
  map<char, vector<int> > mp;
  mp['c'] = { 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 };
  mp['d'] = { 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0 };
  mp['e'] = { 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0 };
  mp['f'] = { 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0 };
  mp['g'] = { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  mp['a'] = { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
  mp['b'] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
  mp['C'] = { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
  mp['D'] = { 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0 };
  mp['E'] = { 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0 };
  mp['F'] = { 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 };
  mp['G'] = { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  mp['A'] = { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
  mp['B'] = { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
  int t, turn = 0;
  (cin >> t).ignore();
  while (t--)
  {
    //string tem;
    //getline(cin, tem);
    //cin.ignore();
    string s;
    getline(cin, s);
    vector<int>finger(11, 0);
    vector<int>check(11, 0);

    if (s == " ") {
      for (int i = 0;i < 10;i++) {
        cout << '0';
        if (i != 10)cout << ' ';
      }
      cout << endl;
      continue;
    }
    for (int i = 0;i < s.length();i++) {
      for (int j = 1;j <= 10;j++) {
        if (mp[s[i]][j]) {
          if (check[j] == 0) {
            finger[j]++;
            check[j] = 1;
          }
        }
        else {
          check[j] = 0;
        }
      }
    }
    for (int i = 1;i <= 10;i++) {

      cout << finger[i];
      if (i != 10)cout << ' ';
    }
    cout << endl;

  }



  return 0;
}
```
