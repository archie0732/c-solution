# Perfect Squares

`DP`/`BFS` 

[題目連結](https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-14)



#### 解題(DP)


* 痾.....直接畫圖(反向推導)

```
數字    組合    步數 //備註(組合數字+1)
1   ==>  1     (1)
2   ==>  1+1   (2) // 1+1
3   ==>  1+1+1 (3) // 2+1
4   ==>  4     (1)
5   ==>  4+1   (2) // 4+1
6   ==>  4+1+1 (3) // 4+2+1
.
.
.
(略
......直到你要找的數字
```
#### code
* cpp
```cpp
class Solution {
public:
    int numSquares(int n) {
        //too smart
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            int tem = INT_MAX;
            for(int j=1;i>=j*j;j++){
                tem = min(dp[i-j*j],tem);
            }
            dp[i] = tem+1;
        }
        return dp[n];
    }
};
```
* js
```js
/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    let dp = new Array(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(let i=2;i<=n;i++){
        let tem = 10000000000000;
        for(let j=1;j*j<=i;j++){
            tem = Math.min(tem,dp[i-j*j]);
        }
        dp[i] = tem+1;
    }
    return dp[n];
};
```

