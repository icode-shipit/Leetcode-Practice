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

   void levelorder(vector<vector<int>> &v,TreeNode* root)
{ 
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty())
  {
    vector<int> temp;
    int levelsize=q.size();
    for(int i=0;i<levelsize;i++)
    {
    if(q.front()->left!=NULL)
    {
        q.push(q.front()->left);
    }
    if(q.front()->right!=NULL)
    {
        q.push(q.front()->right);
    }
    temp.push_back(q.front()->val);
    q.pop();
    }
    v.push_back(temp);
  }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        {
          return {};
        }
        else
        {
        vector<vector<int>> v;
        levelorder(v,root);
        return v;
        }
    }
};
