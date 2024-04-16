# Binary Tree Inorder Traversal

[題目連結](https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16)

* left inorder 遍歷


#### code

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
    TreeNode add(TreeNode root ,int val, int depth,int d){

        // 如果有一邊是null
        if(root==null )return null;

        if(depth==d+1){
            TreeNode t1 = root.right,t2 = root.left;
            
            // add new val
            root.right = new TreeNode(val);
            root.left = new TreeNode(val);
            
            // add odd point
            root.right.right = t1;
            root.left.left = t2;
            return root;
        }
        else{
           root.left = add(root.left,val,depth,d+1);
           root.right = add(root.right,val,depth,d+1); 
        }

        return root;
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {

        if(root==null)return null;

        if(depth==1){
            TreeNode a = root;
            root = new TreeNode(val);
            root.left = a;
            return root;
        }

        return add(root,val,depth,1);
        
    }
}
```
