# Palindrome Number

[題目連結](https://leetcode.com/problems/palindrome-number/description/)


#### 解題

1. 頭與尾互相比較一步一樣，結束


#### code

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.size()/2;
        for(int i =0 ;i<n;i++){
            if(s[i]!=s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
```
