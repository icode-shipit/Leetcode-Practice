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
    void preorder(TreeNode* root,int sum,int target,bool &ans)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left==NULL && root->right==NULL)
        {
            if(sum+root->val==target)
            {
                ans= true;
            }
        }
        preorder(root->left,sum+root->val,target,ans);
        preorder(root->right,sum+root->val,target,ans);
        return;
    }
 
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return false;
        }
        bool ans=false;
    preorder(root,0,targetSum,ans);
    return ans;
    }
};
