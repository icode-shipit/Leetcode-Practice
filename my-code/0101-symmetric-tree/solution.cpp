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
    bool recursivecheck(TreeNode* left,TreeNode* right)
    {
       if(left==NULL && right==NULL)
       {
        return true;
       }
       else if(left==NULL || right==NULL)
       {
        return false;
       }
        return (left->val==right->val && recursivecheck(left->right,right->left) && recursivecheck(left->left,right->right));
    }
    bool isSymmetric(TreeNode* root) {
        return recursivecheck(root->left,root->right);
    }
};
