//Even Odd Tree
//mid
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
    public boolean isEvenOddTree(TreeNode root) {

        // create a new queue
        Queue<TreeNode> q = new LinkedList<TreeNode>();

        // push back root
        q.offer(root);
        //set begin level is 1
        int level = 1;

        // while tree have children
        while(!q.isEmpty()){
            
            int qsize = q.size();
            // if odd in || if even de
            int pre = level % 2 == 1 ? -1 : Integer.MAX_VALUE;

            while(qsize-- > 0){
                // get the top tree
                TreeNode node = q.poll();

                // the rule 
                if(level % 2 == 0){
                    if(node.val % 2 == 1 || pre <= node.val) return false;
                }
                else{
                    if(node.val % 2 == 0 || pre >= node.val) return false;
                }

                // to cmp with next
                pre = node.val;

                // have chidren ? add : nothing
                if(node.left != null) q.offer(node.left);
                if(node.right != null) q.offer(node.right);
            }
            // level up
            level++;
        }

        //follow all rule 
        return true;

    }
}
