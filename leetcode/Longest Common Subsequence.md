# Longest Common Subsequence

[題目連結](https://leetcode.com/problems/longest-common-subsequence/?envType=daily-question&envId=2024-01-25)

#### 解題
用`lcs`結束

#### code(java)

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        
        int[][] matrix = new int [text1.length()+2][text2.length()+2];
        for(int i=0;i<text2.length();i++){
            matrix[0][i]=0;
        }
        for(int i=0;i<text1.length();i++){
            for(int j=0;j<text2.length();j++){
                if(text1.charAt(i)==text2.charAt(j)){
                    matrix[i+1][j+1]=matrix[i][j]+1;
                }
                else{
                    matrix[i+1][j+1] = Math.max(matrix[i][j+1],matrix[i+1][j]);
                }
            }
        }

        return matrix[text1.length()][text2.length()];

    }
}
```
