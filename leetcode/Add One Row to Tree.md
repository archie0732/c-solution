# Add One Row to Tree (623)

* 在原本的`二元樹`的某一層插入新節點(後面一樣是舊節點)

用`bfs`遍歷樹(直到到要補的層**前**)，插入左值與右值(可能為`null`)

* 注意題目要替換的層樹可以是第一層(有指定是左邊續接`root`)

#### code (java) 

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
