//Bitwise AND of Numbers Range
//mid

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        //推到相同
        while(left!=right){
            left >>=  1;
            right >>= 1;
            ans++;
        }
        //AND 
        /*
         * 0 0  ==> 0
         * 1 1  ==> 1
         * 0 1  ==> 0
         * 1 0  ==> 0
         即：相同時在推回去就完成了
        */
        return left<<ans;
    }
};

