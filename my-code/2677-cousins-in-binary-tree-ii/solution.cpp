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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL)
        {
            return root;
        }
        if(root->left==NULL && root->right==NULL)
        {
            root->val=0;
            return root;
        }
        root->val=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize=q.size();
            int nxtlevelsum=0;
            vector<TreeNode*> temp; //stores nodes of current level
            for(int i=0;i<levelsize;i++)
            {
               if(q.front()->left!=NULL)
               {
                q.push(q.front()->left);
                nxtlevelsum+=q.front()->left->val;
               }
               if(q.front()->right!=NULL)
               {
                q.push(q.front()->right);
                nxtlevelsum+=q.front()->right->val;
               }
               temp.push_back(q.front());
               q.pop();
            }
            for(int i=0;i<temp.size();i++)
            {
               if(temp[i]->left!=NULL)
               {
                 if(temp[i]->right!=NULL)
                 {
                    temp[i]->left->val=nxtlevelsum-(temp[i]->left->val+temp[i]->right->val);
                    temp[i]->right->val=temp[i]->left->val;
                 }
                 else
                 {
                    temp[i]->left->val=nxtlevelsum-(temp[i]->left->val);
                 }
               }
               else if(temp[i]->right!=NULL)
               {
                    temp[i]->right->val=nxtlevelsum-(temp[i]->right->val);
               }
            }
        }
        return root;
    }
};
