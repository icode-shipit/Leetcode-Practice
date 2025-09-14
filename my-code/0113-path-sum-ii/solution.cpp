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
   void preorder(TreeNode* root,vector<vector<int>> &v1,int targetSum,int sum,vector<int> &v)
   {
    if(root==NULL)
    {
        return;
    }
    v.push_back(root->val);
    if(root->left==NULL && root->right==NULL)
    {
        if(sum+root->val==targetSum)
        {  
        v1.push_back(v);
        }
    }
    preorder(root->left,v1,targetSum,sum+root->val,v);
    preorder(root->right,v1,targetSum,sum+root->val,v);
    v.pop_back();
    return;
   }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        vector<vector<int>> v1;
        preorder(root,v1,targetSum,0,v);
        return v1;

    }
};
