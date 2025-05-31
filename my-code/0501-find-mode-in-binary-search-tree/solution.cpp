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
    void inorder(TreeNode* root,map<int,int> &data)
        {
            if(root==NULL)
            {
                return;
            }
            inorder(root->left,data);
            if(data[root->val]==0)
            {
              data[root->val]=1;
            }
            else 
            {
                data[root->val]++;
            }
            inorder(root->right,data);
        }
    vector<int> findMode(TreeNode* root) {
        map<int,int> data;
        inorder(root,data);
        int max=-1;
        for(pair<int,int> map:data) // for finding element with max freq
        {
            if(map.second>max)
            {
                max=map.second;
            }
        }
        vector<int> output;
        for(pair<int,int> map:data) // finding node which has same max freq
        {
            if(map.second==max)
            {
               output.push_back(map.first);
            }
        }
        return output; 
    }
};
