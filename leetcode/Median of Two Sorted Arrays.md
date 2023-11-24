# Median of Two Sorted Arrays

Given two sorted arrays `nums1` and `nums2` of size m and n respectively, return the median of the two sorted arrays.  

The overall run time complexity should be `O(log (m+n))`.  

 

**Example 1**:  

Input: nums1 = [1,3], nums2 = [2]  
Output: 2.00000  
Explanation: merged array = [1,2,3] and median is 2.  
**Example 2**:  

**Input**:  
nums1 = [1,2], nums2 = [3,4]  
**Output**:  
2.50000  

  
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.  
```java
import java.util.Arrays;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
       
        int n = nums1.length;
        int m = nums2.length;

        
        int[] merged = new int[n + m];
        int k = 0;
        for (int i = 0; i < n; i++) {
            merged[k++] = nums1[i];
        }
        for (int i = 0; i < m; i++) {
            merged[k++] = nums2[i];
        }

        Arrays.sort(merged);

    
        int total = merged.length;

        if (total % 2 == 1) {
          
            return (double) merged[total / 2];
        } else {
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return ((double) middle1 + (double) middle2) / 2.0;
        }
    }
}
```
