# Fourth Point !! 

~~老實說，這題很該死，東西都沒給，要自己去找~~


#### 一些題目沒寫的條件

* 給四點，但有兩點重複==>所以實際上是三點
* 重複的一點是與其他兩點相連(不予要求的點相連)


### 解題

假如給四點

* x1 y1
* x2 y2
* x3 y3
* x4 y4

如果x1與x4相同且y點也是如此  

結果如下圖(點用o表示，例如o1就是x1,y1)
```
      o2 ' '  '  ?
    '          '
  '          '
o1 ' '  ' o3
```
要求o4

==>利用國中所學的向量

* x2+x3-x1 = x4
* y2+y3-y1 = y4

所以解題步驟

1. 先找到重複的點
2. 把重複的點放到x1,y1的位置，剩下o2,o3沒差
3. 利用向量公式算出答案

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

bool compareByValue(const pair<pair<double, double>, int> &a, const pair<pair<double, double>, int> &b)
{
    return a.second > b.second;
}

int main(int argc, char const *argv[])
{
    pair<double, double> ans[4];

    while (cin >> ans[0].first >> ans[0].second >> ans[1].first >> ans[1].second >> ans[2].first >> ans[2].second >> ans[3].first >> ans[3].second)
    {
        map<pair<double, double>, int> check;
        check[ans[0]]++;
        check[ans[1]]++;
        check[ans[2]]++;
        check[ans[3]]++;

        vector<pair<pair<double, double>, int>> keyValuePairs(check.begin(), check.end()); // 修正这里

        sort(keyValuePairs.begin(), keyValuePairs.end(), compareByValue);

        int i = 0;
        for (auto it : keyValuePairs)
        {
            ans[i] = it.first;
            i++;
        }

        printf("%.3f %.3f\n", (ans[1].first + ans[2].first) - ans[0].first, (ans[1].second + ans[2].second) - ans[0].second);
    }
    return 0;
}
```

```cpp
#include<bits/stdc++.h>

using namespace std;


int main(){

	pair<double,double> p1,p2,p3,p4 ;
	
	while(cin>>p1.first>>p1.second>>p2.first>>p2.second>>p3.first>>p3.second>>p4.first>>p4.second){
		
		if(p1==p2)p2 = p4;
		else if(p1 == p3)p3 = p4;
		else if(p2 == p3){
			swap(p1,p2);
			swap(p3,p4);
		}
		else if(p2 == p4){
			swap(p2,p1);
		}
		else if(p3==p4){
			swap(p1,p3);
		}
		
		double v1_x = p2.first - p1.first;
		double v2_x = p3.first - p1.first;
		double v1_y = p2.second - p1.second;
		double v2_y = p3.second - p1.second;
		
		double ans_x = (v1_x+v2_x)+p1.first;
		double ans_y = (v1_y+v2_y)+p1.second;
		
		printf("%.3f %.3f\n",ans_x,ans_y);
	}

	return 0;
}
```
