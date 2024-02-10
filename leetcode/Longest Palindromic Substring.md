# Longest Palindromic Substring

`DP` `string`  
[題目連結](https://leetcode.com/problems/longest-palindromic-substring/description/)

#### 解題

* ~~用動規去遍歷整個字串~~ (記憶體會先炸)
* 經歷整個字串==>必看其最後能夠擴展多少格(符合回唯才可以再擴展)



#### code


```cpp
class Solution {
public:
    pair<int, int> expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        
        for (int i = 0; i < s.size(); i++) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
```

