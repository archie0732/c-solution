# Tell me the frequencies!

[題目連結](https://vjudge.net/problem/UVA-10062)

#### 大致題意

 * 算一行字裡的字元出現頻率，案輸出要照以下規則
   >按照出現頻率  (由小至大)  
   >頻率一樣就按照ASCII碼(由大至小)
   >字元輸出使用ASCII碼

#### 解題

1. 用map計次數與把字元轉ASCII碼(char==>int)
2. 用`vector`與`sort`(建立排序規則)
3. 輸出

###### 注意Presentation Error(不要最後面換行，改到前面)


#### code

```cpp
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second)
    return a.second < b.second;
  else {
    return a.first > b.first;
  }
}

int main(int argc, char const* argv[])
{
  int turn = 0;
  string s;
  while (getline(cin, s))
  {
    if (turn != 0) {
      cout << endl;
    }
    map<int, int> count;
    for (int i = 0;i < s.length();i++) {
      count[s[i]]++;
    }
    //  cout << "succes" << endl;
    vector<pair<int, int>>v;
    for (auto it : count) {
      v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);

    for (const auto& it : v) {
      cout << it.first << " " << it.second << endl;
    }
    turn++;

  }


  return 0;
}
```
