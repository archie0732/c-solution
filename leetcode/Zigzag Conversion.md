# Zigzag Conversion

[題目連結](https://leetcode.com/problems/zigzag-conversion/description/)


#### 解題

* 遞增==>碰到底==>變成遞減==>碰到頭==>變成遞增....


#### code 



```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty())return "";
        if(s.size()==1||numRows==1)return s;

        string ans;
        string tem[numRows]; 
        int flag = -1,row=0;

        for(int i=0;i<s.size();i++){
            if(row==0||row==numRows-1)flag*=-1;
            tem[row]+=s[i];

            flag==1 ? ++row : --row;
        }
        for(int i=0;i<numRows;i++){
            ans+=tem[i];
        }
        return ans;
    }
};
```
