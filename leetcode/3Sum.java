//3Sum
//mid
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
      //先排序
      Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < nums.length - 2; i++) {
          //如果與前面之元素相同==>跳過，不然會得到相同答案  
          if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            //中間指標與末尾
            int mid = i + 1;
            int back = nums.length - 1;

            while (mid < back) {
                int sum = nums[i] + nums[mid] + nums[back];
                //合計為0及加入答案列表
                if (sum == 0) {
                    ans.add(Arrays.asList(nums[i], nums[mid], nums[back]));

                    while (mid < back && nums[mid] == nums[mid + 1]) {
                        mid++;
                    }
                    while (mid < back && nums[back] == nums[back - 1]) {
                        back--;
                    }
                    mid++;
                    back--;
                } else if (sum < 0) {
                    mid++;
                } else {
                    back--;
                }
            }
        }

        return ans;
    }
}
