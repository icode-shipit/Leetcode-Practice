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
    bool ans=false;
    int target;
    void dfs(TreeNode* root,int sum)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL) dfs(root->left,sum+root->left->val);
        else if(root->left==NULL) dfs(root->left,sum);
        if(root->right!=NULL) dfs(root->right,sum+root->right->val);
        else if(root->right==NULL) dfs(root->right,sum);
        if(root->left==NULL && root->right==NULL && target==sum)
        {
            ans=true;
        }
        return ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return false;
        }
        target=targetSum;
        dfs(root,root->val);
        return ans;
    }
};
