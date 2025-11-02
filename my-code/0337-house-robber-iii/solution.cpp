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
   pair<int,int> dfs(TreeNode* root) // first->withroot maxmoney ,second->withroot maxmoney
   {
    if(root==NULL)
    {
      return {0,0};
    }
    pair<int,int> leftpair=dfs(root->left);
    pair<int,int> rightpair=dfs(root->right);
    
    int withroot=root->val+leftpair.second+rightpair.second;
    int withoutroot=max(leftpair.first,leftpair.second)+max(rightpair.first,rightpair.second);
    return {withroot,withoutroot};  
   }

    int rob(TreeNode* root) {
        pair<int,int> ans=dfs(root);
        return max(ans.first,ans.second);
    }
};
