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

vector<TreeNode*> generateTree(int left,int right)
{
   vector<TreeNode*> bucket;

   if(left==right)
   {
      TreeNode* newnode=new TreeNode(left);
      vector<TreeNode*> v;
      v.push_back(newnode);
      return v;
   }
   else if(left>right)
   {
    return {nullptr};
   }

    for(int val=left;val<=right;val++)
    {
        vector<TreeNode*> v= generateTree(left,val-1); // leftTree
        for(int j=0;j<v.size();j++)
        {
            TreeNode* leftTree=v[j];
            vector<TreeNode*> v1 = generateTree(val+1,right); // rightTree
            for(int i=0;i<v1.size();i++)
            {
                TreeNode* rightTree=v1[i];
                TreeNode* root=new TreeNode(val,leftTree,rightTree);
                bucket.push_back(root);
            }
        }
    }
    return bucket;
}

    vector<TreeNode*> generateTrees(int n) {
        return generateTree(1,n);
    }
};
