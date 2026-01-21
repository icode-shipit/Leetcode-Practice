/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root,TreeNode* &ans,TreeNode* p,TreeNode* q,int &i)
    {
        if(root==NULL)
        {
            return false;
        }
        bool leftcheck=dfs(root->left,ans,p,q,i);
        bool rightcheck=dfs(root->right,ans,p,q,i);
        if((leftcheck && rightcheck) || ((leftcheck || rightcheck )&& (root==p || root==q)))
        {
            if(i==0)
            {
            i++;
            ans=root;
            return true;
            }
        }
        else if(leftcheck || rightcheck || root==p || root==q)
        {
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=root;
        int i=0;
        bool random=dfs(root,ans,p,q,i);
        return ans;
    }
};
