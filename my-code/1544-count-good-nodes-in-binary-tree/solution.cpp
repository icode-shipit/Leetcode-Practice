/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(int &count, int maxval, TreeNode* root)
    {
      if(root==NULL)
      {
        return;
      }
      maxval=max(maxval,root->val);
      if(root->val>=maxval)
      {
        count++;
      }
      dfs(count,maxval,root->left);
      dfs(count,maxval,root->right);
      return;
    }

    int goodNodes(TreeNode* root) {
        int count=0;
        dfs(count,INT_MIN,root);
        return count;
    }
};
