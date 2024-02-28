#### 題目意思

從s裡找到最長的對稱字串

#### 解題

根據題意，而且標籤有`dp`，基本可以先建表

* 假設題目是bababa => 建立表格

 | |b|a|b|a|b|a
-|-|-|-|-|-|-
b| | | | | | 
a| | | | | | 
b| | | | | | 
a| | | | | |
b| | | | | | 
a| | | | | | 

* 表格意義 ==> 所有字串的組合 ==> 如下圖


 | |b|a|b|a|b|a
-|-|-|-|-|-|-
b| b|ba |bab |baba |babab |bababa 
a| /| a| ab|aba |abab |ababa 
b| /| /| b|ba| bab|baba 
a| /| /| /|a | ab|aba
b| /| /| /| /| b| ba
a| /|/ |/ |/ | /| a|


* 我們只要判斷這格是不是對稱的就行了，也就是==>判斷頭與尾是否相同
  >相同: 去看減去頭與尾的字串是否對稱  
  >不同: 會報這格是非對稱(這樣下次有相同的頭尾時查找這格時就可以直接給答案


  ![](https://i.pixiv.cat/img-original/img/2024/02/03/20/10/20/115730211_p1.png)   
  
```java
class Solution {
    public String longestPalindrome(String s) {
        String ans = "";
        int n = s.length();
        ans+=s.charAt(0);

        boolean[][] dp = new boolean[n][n];

        for(int i = 0;i < n;i++) dp[i][i] = true;

        //size is 2
        for(int i = 0;i < n;i++){
            if(i + 1 < n && s.charAt(i) == (s.charAt(i+1))){
                dp[i][i+1] = true;
                if(ans.length() < 2) ans = s.substring(i,i+2);
            }
        }

        // size > 2
        // len + start < n
        for(int len = 2;len<n;len++){
            for(int start = 0;len + start < n;start++){
                int end = start + len;
                if(s.charAt(start) == (s.charAt(end)) && dp[start+1][end-1]){
                    dp[start][end] = true;
                    
                    String temp = s.substring(start,end+1);

                    ans = temp.length() > ans.length() ? (temp): (ans); 
                }
            }
        }


        return ans;
    }
}
```
