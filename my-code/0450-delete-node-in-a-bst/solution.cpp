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
    int maxnode(TreeNode* root)
    {
        TreeNode* temp=root;
        while(temp->right!=NULL)
        {
          temp=temp->right;
        }
        return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return {};
        }
        
        if(root->val==key)
        {
        if(root->left!=NULL && root->right==NULL) // left child case
        {
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->right!=NULL && root->left==NULL) //right child case
        {
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right!=NULL && root->left!=NULL) //both child case
        {
            int maxval=maxnode(root->left);
            root->val=maxval;
            root->left=deleteNode(root->left,maxval);
            return root;
        } 
        else
        {
            delete root;
            return {};
        }
        }

        else if(root->val<key)
        {
           root->right=deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
           root->left=deleteNode(root->left,key);
        }

        return root;
    }
};
