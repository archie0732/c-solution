//Climbing Stairs
//Easy
class Solution {
    public int climbStairs(int n) {
        // create a dp array
        int [] dp = new int [n+1];

        // to avoid array overflow
        if(n <= 1) return n;

        /* 0 ==> (0 method
         * 1 ==> (1 method
         * 2 ==> 0 -> 1 -> 2 or 0 -> 2 (2 method
        */
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        // for n = 3 u have 2 method
        // from n = 1 to n = 3 "or" from n = 2 to n = 3 
        // and to n = 1 have 1 method "and"  to n = 2 have 2 method
        // 
        // and we can get to a conclusion 
        // if we want go to n
        // we can get n-1 + n-2 ==> to n
        for(int i = 3 ;i <= n;i++){
            dp[i] = dp[i-1] +dp[i-2];
        } 

        return dp[n];
    }
}
