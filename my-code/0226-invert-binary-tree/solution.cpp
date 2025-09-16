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
    void levelorder(TreeNode* root)
    {
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        if(q.front()->left!=NULL || q.front()->right!=NULL)
        {
          TreeNode* temp=q.front()->right; 
          q.front()->right=q.front()->left;
          q.front()->left = temp;
        }
        if(q.front()->left!=NULL)
        {
          q.push(q.front()->left);
        }
        if(q.front()->right!=NULL)
        {
          q.push(q.front()->right);
        }
        q.pop();
      }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        levelorder(root);
        return root;
    }
};
