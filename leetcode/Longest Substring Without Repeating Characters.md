# Longest Substring Without Repeating Characters

[題目連結](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)  



#### 解題

* 我是用最笨的方法==>一個一個看他可以延伸到的最長子陣列，再逐一比較

#### code 

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        if(s=="")
            return 0;
        if(s.size()==1){
            return 1;
        }
        for(int i=0;i<s.size()-1;i++){
            set<int> check;
            check.insert(s[i]);
            int tem=1;
            for(int j=i+1;j<s.size();j++){
                if(check.count(s[j])){
                    break;
                }
                check.insert(s[j]);
                tem++;
            }
            ans = max(ans,tem);
        }
        return ans;
    }
};
```
