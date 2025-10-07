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

    void preorder(TreeNode* root,vector<int> &v) //helper 1
    {
    if(root==NULL)
    {
        return;
    }
    v.push_back(root->val);
    preorder(root->left,v);
    preorder(root->right,v);
    return;
    }

    void helper(TreeNode* root,vector<int> &v,int i)
    {
     if(i<v.size())
     {
        if(i==1)
        {
      delete root->right;
      root->right=NULL;  
      delete root->left;
      root->left=NULL;
        }
      TreeNode* newnode= new TreeNode();
      root->right=newnode;
      newnode->val=v[i];
      helper(newnode,v,++i);
     }
     else
     {
        return;
     }
    }

    void flatten(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        helper(root,v,1);
        return ;
    }
};
