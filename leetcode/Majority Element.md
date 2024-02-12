# Majority Element

[題目連結](https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12)  


#### 解題

* 用`map`紀錄出現幾次==>輸出出現最多次的==>結束!

#### code

```cpp
class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    int majorityElement(vector<int>& nums) {
        map <int,int> mymap;
        for(int i = 0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        vector<pair<int,int>> v(mymap.begin(),mymap.end());
        
        sort(v.begin(),v.end(),cmp);
        return v.front().first;
    }
};
```
