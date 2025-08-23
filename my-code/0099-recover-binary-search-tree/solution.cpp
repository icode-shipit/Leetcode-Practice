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
    void inorder(TreeNode* root,int &i,TreeNode* &prev,TreeNode* &Node1,TreeNode* &Node2)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,i,prev,Node1,Node2);
        if(prev!=NULL && prev->val>root->val)
        {
            if(i==0)
            {
           Node1=prev;
           prev=root;
            Node2=root;
           i++;
            }
            else
            {
                Node2=root;
            }
        }
        else
        {
            prev=root;
        }
        inorder(root->right,i,prev,Node1,Node2);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* Node1=NULL;
        TreeNode* Node2=NULL;
        TreeNode* prev=NULL;
        int i=0;
        inorder(root,i,prev,Node1,Node2);
        int temp=Node1->val;
        Node1->val=Node2->val;
        Node2->val=temp;
        return ;
    }
};
