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
    TreeNode* Levelordertraversal(TreeNode* root,int p,int q)
    {
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
          TreeNode* temp=Q.front();
          if(temp->val==p || temp->val==q)
          {
            if(temp->val==p)
            {
                return temp;
            }
            else if(temp->val==q)
            {
                return temp;
            }
          }
          else if((temp->val)>p && (temp->val)<q)
          {
            return temp;
          }
          else if((temp->val)<p && (temp->val)>q)
          {
            return temp;
          }
          Q.pop();  
          if(temp->left!=NULL)
          {
            Q.push(temp->left);
          }
          if(temp->right!=NULL)
          {
            Q.push(temp->right);
          }
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // I will do level order traversal and while traversal i will check 3 conditions
        //cond1->if root->value<p && >q || root->value>p && <q then return root->value
        //cond2->if root->value==p || q then return root->value
      TreeNode* temp=Levelordertraversal(root,p->val,q->val);
      return temp;
    }
};
