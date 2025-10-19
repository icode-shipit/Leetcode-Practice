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
    void levelorder(TreeNode* root,vector<int> &v)
    {
      queue<TreeNode*> q;
      if(root==NULL)
      {
        return;
      }
      q.push(root);
      int levelsize=0;
      while(!q.empty())
      {
        levelsize=q.size();
        for(int i=0;i<levelsize;i++)
        {

        //feeding elements into array
        if(q.front()->left!=NULL)
        {
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL)
        {
            q.push(q.front()->right);
        }
        
        //pushing elements into required array
        if(i==levelsize-1)
        {
        v.push_back(q.front()->val);
        }
        
        q.pop();

        }
      }        
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        levelorder(root,v);
        return v;
    }
};
