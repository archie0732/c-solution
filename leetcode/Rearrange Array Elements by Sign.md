# Rearrange Array Elements by Sign 

[題目連結](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14)


#### 解題

* 依據題意將認列依序正負分開，在依據正負放入`ans`內


#### code


```cpp

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        std::vector<int> p;
        std::vector<int> n;

        // 將正數和負數分開存儲
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0)
                p.push_back(nums[i]);
            else
                n.push_back(nums[i]);
        }

        // 創建結果向量
        std::vector<int> ans;

        // 使用迴圈處理正數和負數向量
        for (int i = 0; i < std::max(p.size(), n.size()); i++) {
            if (i < p.size())
                ans.push_back(p[i]);
            if (i < n.size())
                ans.push_back(n[i]);
        }

        return ans;
    }
};

```
