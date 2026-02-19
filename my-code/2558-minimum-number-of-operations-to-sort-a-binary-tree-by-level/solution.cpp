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
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            unordered_map<int,int> m;
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
            m.insert({q.front()->val,temp.size()-1});
            q.pop();
            }
            vector<int> sortedtemp(temp);
            sort(sortedtemp.begin(),sortedtemp.end());
            for(int i=0;i<sortedtemp.size();i++)
            {
                if(temp[i]!=sortedtemp[i])
                {
                  int pos=m[sortedtemp[i]];
                  swap(temp[m[sortedtemp[i]]],temp[i]);
                  m[temp[i]]=i;
                  m[temp[pos]]=pos;
                  ans++;
                }
            }
        }
        return ans;
    }
};
