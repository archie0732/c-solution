# Sort Characters By Frequency


[題目連結](https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07)  



#### 解題

* 用`map`去排列字串與其出現的次數==>最後在按次數輸出



#### code


```cpp
class Solution {
public:
    static bool cmp(pair<char,int>a,pair<char,int>b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map <char,int> mymap;
        for(int i=0;i<s.size();i++){
            mymap[s[i]]++;
        }
        vector <pair<char,int>> ans;
        for(auto it : mymap){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end(),cmp);
        string x;
        for(auto it : ans){
            x.append(it.second,it.first);
        }
        return x;
    }
};
```
