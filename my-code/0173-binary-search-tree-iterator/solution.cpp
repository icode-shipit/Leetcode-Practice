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
class BSTIterator {
public:
    vector<int> v;
    int tracker=0;
    void inorder(TreeNode* temp1,vector<int> &v)
    { 
      if(temp1==NULL)
      {
        return ;
      }
      inorder(temp1->left,v);
      v.push_back(temp1->val);
      inorder(temp1->right,v);
    }

    BSTIterator(TreeNode* root) {
        inorder(root,v);  
    }
    
    int next() {
      return v[tracker++];
    }
    
    bool hasNext() {
        if(tracker>=v.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
