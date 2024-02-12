# Container With Most Water

[題目連結](https://leetcode.com/problems/container-with-most-water/description/)

>[!note]
>原本是想要直接遍歷整個陣列，    
>但會在case 55 直接被搞死XD

#### 解題

* 用貪心去看左邊與右邊，並根據規則算出高度
* 至於移動方法就是看左右指標誰比較小就往中間移動一格(目的是找比另一邊還要高的值)


#### code


```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0,r = height.size()-1;
        while(l<r){
           int w = r - l;
           int h;
           if(height[r]>height[l]){
               h = height[l];
               l++;
           }
           else{
               h = height[r];
               r--;
           }
           ans = max(h*w,ans); 
        }
        return ans;
    }
};
```
