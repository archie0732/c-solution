# Smallest String Starting From Leaf

[題目連結](https://leetcode.com/problems/smallest-string-starting-from-leaf/description/?envType=daily-question&envId=2024-04-17)

* 用bfs來做

1.先移路往左走(直到左邊是`null`)，刪掉當下的點(往回走)，再往右下去
2.如果右邊也走到`null`那就回到在上面的點

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
    String ans=""; 
    private void bfs(TreeNode root ,StringBuffer s){

        if(root == null)return;

        s.append((char)('a'+root.val));

        if(root.left == null && root.right == null){   
            String tem = s.reverse().toString();
            s.reverse();
            if(ans=="" || ans.compareTo(tem)>0){
                ans = tem;
            }
        }

        bfs(root.right,s);
        bfs(root.left,s);

        s.deleteCharAt(s.length()-1);
    }

    public String smallestFromLeaf(TreeNode root) {
        bfs(root,new StringBuffer());

        return ans;
    }
}
```
