# What’s Cryptanalysis?

[題目連結](https://onlinejudge.org/external/100/10008.pdf)  

簡單來說就是給行字串(**有空格**)，算字母出現幾次(不包含**數字**、**標點符號**與**空白**)   


#### 解題 

1. 建一個`map`
2. 把字串中的字母換成大寫 (`toupper`)
3. 用指標檢查是不是字母 (`isalpha`)
4. 依照出現多寡排序 (sort、vector)




#### code 

![](https://th.bing.com/th/id/R.a98067b2ef86496ec1a9260defb970ab?rik=ijQswUrLMwRgeg&riu=http%3a%2f%2fi1.hdslb.com%2fbfs%2farchive%2f7b7232f95def9f4742c59b476016b05463b56756.jpg&ehk=j32EP2W22KktrK3yx0br%2bAKVdqpENJ56yeHRKXsuZBI%3d&risl=&pid=ImgRaw&r=0)  

```cpp
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool sortByValue(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second > b.second; 
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    cin.ignore(); 
    string s;
    map<char, int> ans;

    for (int i = 0; i < t; i++)
    {
        getline(cin, s);
        for (char &it : s)
        {
            it = toupper(it);
            if (isalpha(it))
                ans[it]++;
        }
    }

    
    vector<pair<char, int>> sortedAns(ans.begin(), ans.end());
    sort(sortedAns.begin(), sortedAns.end(), sortByValue);

    
    for (auto it : sortedAns)
        cout << it.first << " " << it.second << endl;

    return 0;
}
```


