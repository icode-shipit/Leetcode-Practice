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

public class pair
{
  int first;int second;
   pair(int left,int right)
  {
    this.first=left;
    this.second=right;
  }
}

class Solution {
    pair dfs(TreeNode root) //first->withroot max,second->withoutroot max
    {
        if(root==null)
        {
            return new pair(0,0);
        }
        pair leftpair= dfs(root.left);
        pair rightpair= dfs(root.right);
        int left=root.val+leftpair.second+rightpair.second;
        int right=Math.max(leftpair.first,leftpair.second)+Math.max(rightpair.first,rightpair.second);
        return new pair(left,right);
    }
    public int rob(TreeNode root) {
        pair ans=dfs(root);
        return Math.max(ans.first,ans.second);
    }
}
