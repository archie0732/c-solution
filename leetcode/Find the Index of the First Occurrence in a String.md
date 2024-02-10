# Find the Index of the First Occurrence in a String

`string`
[題目連結](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)



#### 解題

* 去找相同，結束

#### code 


```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = needle.size();
        for(int i = 0;i<haystack.size();i++){
            if(haystack.substr(i,x)==needle){
                return i;
            }
        }
        return -1;
    }
};
```

