# Palindromic Substrings

`DP` `string`

[題目連結]()


#### 解題

* 用`動態規劃`去遍歷字串中所有種類的組合==>再依序判斷自不是回文


#### code 


```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int ans= 0;
        for(int i= 0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                int flag = 0;
                int l = i,r = j;
                while(l<r){
                    if(s[l]!=s[r]){
                        flag = 1;
                        break;
                    }
                    l++;
                    r--;
                }
                if(flag==0)ans++;
                
            }
        }
        return ans;
    }
};
```
