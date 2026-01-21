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
        int curr_level=0;
        vector<TreeNode*> temp;
        temp.push_back(root);
        while(!q.empty())
        {
            if(curr_level%2==0)
            {
               if(temp.size()==1)
               {
                  int temp1=temp[0]->right->val;
                  temp[0]->right->val=temp[0]->left->val;
                  temp[0]->left->val=temp1;
                  temp.clear();
               }
               else
               {
                int p1=0;
                int p2=temp.size()-1;
                while(p1<p2)
                {
                    if(temp[p2]->left!=NULL)
                    {
                    int temp1=temp[p2]->left->val;
                    int temp2=temp[p2]->right->val;
                    temp[p2]->left->val=temp[p1]->right->val;
                    temp[p2]->right->val=temp[p1]->left->val;
                    temp[p1]->left->val=temp2;
                    temp[p1]->right->val=temp1;
                    p1++;
                    p2--;
                    }
                    else
                    {
                        break;
                    }
                }
                temp.clear();
               }
            }
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++)
            {
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
                q.push(q.front()->right);
                if(curr_level%2!=0)
                {
                    temp.push_back(q.front()->left);
                    temp.push_back(q.front()->right);
                }
            }
            q.pop();
            }
            curr_level++;
        }
        return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root->left==NULL)
        {
            return root;
        }
        levelorder(root);
        return root;
    }
};
