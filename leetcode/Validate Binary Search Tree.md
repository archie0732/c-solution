# Validate Binary Search Tree

[題目連結](https://leetcode.com/problems/validate-binary-search-tree/description/)


```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private boolean btt(TreeNode root,long left_val,long right_val){
        if(root==null)return true;

        if(root.val<=left_val || root.val>=right_val)return false;

        return btt(root.left,left_val,root.val) && btt(root.right,root.val,right_val);
    }
    public boolean isValidBST(TreeNode root) {
        if((root.right==null && root.left==null))return true;
                            //      2147483647
        return btt(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
}
```
