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
    int Minvalue(TreeNode* root)
    {
      TreeNode* temp=root;
      while(temp->left!=NULL)
      {
        temp=temp->left;
      }
      return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->val==key)
        {
            if(root->left==NULL && root->right==NULL)//0 child
            {
            delete root;
            return NULL;
            }
            else if(root->left!=NULL && root->right==NULL)// left child
            {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL && root->right!=NULL)// right child
            {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else
            {
                // we will replace it with min value from the right subtree
                int minvalue=Minvalue(root->right);
                root->val=minvalue;
                root->right=deleteNode(root->right,minvalue);
            }
        }
        else if(root->val>key)
        {
           root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
           root->right=deleteNode(root->right,key);
        }
      return root;
    }
};
