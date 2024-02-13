# Find First Palindromic String in the Array

[題目連結](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13)



#### 解題
* 依照題意，去依序找是否對稱就行

>[!note]
>#### 注意
>如果該字串只有一個，那他就是對稱

#### code

```cpp
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        int flag = 0;
        for(int i=0;i<words.size();i++){
            //一個
            if(words[i].size()==1){
                return words[i];
            }
            for(int j=0;j<words[i].size()/2;j++){
                if(words[i][j]!=words[i][words[i].size()-1-j]){
                    flag = 0;
                    break;
                }
                else{
                    flag = 1;
                }
            }
            if(flag==1){
                return words[i];
            }
        }
        return "";
    }
};
```
