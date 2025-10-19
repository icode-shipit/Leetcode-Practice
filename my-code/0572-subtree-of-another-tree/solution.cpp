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
    bool isSame(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL || subRoot==NULL)
        {
            if(root!=NULL || subRoot!=NULL)
            {
              return false;        
            }
            else
            {
                return true;
            }
        }

      bool leftcheck=isSame(root->left,subRoot->left); 
      bool rightcheck=isSame(root->right,subRoot->right); 
      return leftcheck && rightcheck && root->val==subRoot->val;
    }

    void dfs(TreeNode* root, TreeNode* subRoot,bool &ans)
    {
      if(root==NULL)
      {
        return;
      }  
      if(root->val==subRoot->val)
      {
        if(ans==false)
        {
           ans=isSame(root,subRoot); 
        }
      }
      dfs(root->left,subRoot,ans);
      dfs(root->right,subRoot,ans);
      return;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        dfs(root,subRoot,ans);
        return ans;
    }
};
