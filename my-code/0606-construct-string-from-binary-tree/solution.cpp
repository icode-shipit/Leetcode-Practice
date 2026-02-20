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
    string tree2str(TreeNode* root) {
        if(root==NULL)
        {
           return {}; 
        }
        string ans;
        ans+=to_string(root->val);
        string leftstring=tree2str(root->left);
        string rightstring=tree2str(root->right);
        if(leftstring.empty() && rightstring.empty())
        {
            return ans;
        }
        else if(!leftstring.empty() && rightstring.empty())
        {
            ans+="("+leftstring+")";
            return ans;
        }
        else if(!leftstring.empty() && !rightstring.empty())
        {
            ans+="("+leftstring+")";
            ans+="("+rightstring+")";
            return ans;
        }
        ans+="()";
        ans+="("+rightstring+")";
        return ans;
    }
};
