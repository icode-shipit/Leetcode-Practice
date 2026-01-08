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
    int target;
    Boolean ans=false;
    void dfs(TreeNode root,int sum)
    {
        if(root==null)
        {
            return;
        }
        if(root.left!=null) dfs(root.left,sum+root.left.val);
        else if(root.left==null) dfs(root.left,sum);
        if(root.right!=null) dfs(root.right,sum+root.right.val);
        else if(root.right==null) dfs(root.right,sum);
        if(target==sum && root.left==null && root.right==null)
        {
            ans=true;
        }
        return;
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root==null)
        {
            return false;
        }
        target=targetSum;
        dfs(root,root.val);
        return ans;
    }
}
