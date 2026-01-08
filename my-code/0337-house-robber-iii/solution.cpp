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

    pair<int,int> dfs(TreeNode* root) //first->withroot max,second->withoutroot max
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int> leftpair= dfs(root->left);
        pair<int,int> rightpair= dfs(root->right);
        int left=root->val+leftpair.second+rightpair.second;
        int right=max(leftpair.first,leftpair.second)+max(rightpair.first,rightpair.second);
        return {left,right};
    }

    int rob(TreeNode* root) {
        pair<int,int> ans=dfs(root);
        return max(ans.first,ans.second);
    }
};
