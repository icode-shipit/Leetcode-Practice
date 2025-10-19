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
    int dfs(TreeNode* root,int &diameter)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftheight=dfs(root->left,diameter);
        int rightheight=dfs(root->right,diameter);
        diameter=max(diameter,leftheight+rightheight);
        return max(leftheight,rightheight)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int height=dfs(root,diameter);
        return diameter;   
    }
};
