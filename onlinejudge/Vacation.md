# Vacation

[題目連結](https://vjudge.net/problem/UVA-10192)  



#### 解題 

使用演算法

* DP
 >LCS(Longest Common Subsequence / 找共同子序列)


[LCS演算法](https://github.com/archie0732/c-library/blob/main/algorithm/dp/LCS.md)

1. getline 兩個string 
2. 建立dp二微陣列
3. LCS 演算法找廚共同最大子序列

#### 程式碼(java)

![](https://th.bing.com/th/id/R.57d29bfa1c2b228b465098cc5fd0832f?rik=IvYfCFrCu8EX4A&riu=http%3a%2f%2fi1.kknews.cc%2fBzphk-VLpSgqBWnsA2iSMtrE4Y_ojMjqbQ%2f0.jpg&ehk=MSaLG1EkT0cMdCRg8aHUUdPEt9ijz8lR1ZjjIw8w3Rs%3d&risl=&pid=ImgRaw&r=0)

```java
import java.util.*;

public class Vacation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = 1;
        while (true) {
            String s1 = sc.nextLine();
            if (s1.equals("#")) {
                break;
            }
            String s2 = sc.nextLine();
            
            // dp ==> LCS
            int[][] dp = new int[s1.length() + 1][s2.length() + 1];

            for (int i = 0; i <= s1.length(); i++) {
                Arrays.fill(dp[i], 0);
            }

            for (int i = 0; i < s1.length(); i++) {
                for (int j = 0; j < s2.length(); j++) {
                    if (s1.charAt(i) == s2.charAt(j)) {
                        dp[i + 1][j + 1] = dp[i][j] + 1;
                    } else {
                        dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
                    }
                }
            }
            System.out.println("Case #" + c + ": you can visit at most " + dp[s1.length()][s2.length()] + " cities.");
            c++;
        }

        sc.close();
    }
}
```
