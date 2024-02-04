# Two Sum

[題目連結](https://leetcode.com/problems/two-sum/description/)  


#### 解題

*  用哈希表去遍歷整個vector

#### code (cpp)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i , j};
                }
            }
        }
        return {0,0};
    }
};
```

**java**   

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[] ans = new int[2];
        int flag= 1;
        for(int i = 0;i<n-1 && flag > 0;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    ans[0] = i;
                    ans[1] = j;
                    flag= 0;
                    break;
                }
            }
        }
        return ans;
        
    }
}
```
