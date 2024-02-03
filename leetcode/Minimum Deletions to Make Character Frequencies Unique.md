# Minimum Deletions to Make Character Frequencies Unique

[題目連結](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/)


#### 解題

* 哈希頻率表(Hash_map)

* 因為是往下找，所以發現重疊就往下找不存在於哈希表內的位置

#### code (cpp)

```cpp
class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        map<int,int> Hash_List;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }        
        int ans=0;
        for(auto it : mp ){
            int count = it.second;
            while(Hash_List[count]!=0&&count>0){
                ans++;
                count--;
            }
            if(count>=0)
                Hash_List[count]++;
        }

        return ans;

        
        
    }
};
```

