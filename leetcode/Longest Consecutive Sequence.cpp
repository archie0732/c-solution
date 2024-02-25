//Longest Consecutive Sequence
// mid
#define 原神啟動 on
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int>ans;
        
        int tem = 1 , n = nums.size();
        
        if(n == 0)return 0;

        if(n == 1)return 1;

        for(int i = 0;i < n-1;i++){
            int a = nums[i],b = nums[i+1];
            //soiution
            /*
             * if increase ==> tem++
             * if same ==> nothing
             * else ==> tem restart
            */
            if(a + 1 == b){
                tem++;
            }
            else if(a == b){
                //not thing
            }
            else{
                ans.push_back(tem);
                tem=1;
            }
            if(i == n-2){
                ans.push_back(tem);
            }
        }
        // find the max ans
        sort(ans.begin(),ans.end());
        
        return ans.back();
    }
};
