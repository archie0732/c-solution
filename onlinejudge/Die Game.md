# Die Game

[題目連結](https://vjudge.net/problem/UVA-10409)



#### 解題

1. 已經將整顆骰子的位置給我們了
2. 依法繪製

* 由北至南
  >6、2、1、5、6
  >
* 由西至東
  >6、3、1、4、6

* 當我們**一次只朝一個方向轉動骰子，那麼與其正交之側面兩個位置不變**


 #### code 

 ```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }

    vector<int> r = { 6, 2, 1, 5, 6 };
    vector<int> c = { 6, 3, 1, 4, 6 };

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      switch (s[0]) {
      case 'n':
      {
        r.erase(r.begin());
        int tem = r.front();
        //cout << tem << endl;
        r.push_back(tem);
        c[2] = r[2];
        c.front() = tem;
        c.back() = tem;
      }
      break;
      case 's':
      {
        r.pop_back();
        int tem = r.back();
        r.insert(r.begin(), tem);
        c[2] = r[2];
        c.front() = tem;
        c.back() = tem;
      }
      break;
      case 'e':
      {
        c.pop_back();
        int tem = c.back();
        //cout << tem << endl;
        c.insert(c.begin(), tem);
        r[2] = c[2];
        r.front() = tem;
        r.back() = tem;

      }
      break;
      //西方
      case 'w':
      {
        c.erase(c.begin());
        int tem = c.front();
        c.push_back(tem);
        r[2] = c[2];
        r.front() = tem;
        r.back() = tem;
      }
      break;
      default:
        break;
      }
    }
    cout << r[2] << endl;
  }

  return 0;
}
```
