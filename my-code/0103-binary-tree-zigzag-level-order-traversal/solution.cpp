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
    void levelorder(TreeNode* root,vector<vector<int>> &v)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> tmp;
        tmp.push_back(root->val);
        v.push_back(tmp);
        int level=1;
        while(!q.empty())
        {
          int levelsize=q.size();
          vector<int> temp;
          for(int i=0;i<levelsize;i++)
          {
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
                temp.push_back(q.front()->left->val);
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
                temp.push_back(q.front()->right->val);
            }
            q.pop();
          }
          if(level%2!=0)
          {
            reverse(temp.begin(),temp.end());
          }
          if(!temp.empty())
          {
          v.push_back(temp);
          }
          level++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        levelorder(root,v);
        return v;
    }
};
