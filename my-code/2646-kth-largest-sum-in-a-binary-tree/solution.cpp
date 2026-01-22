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
    void levelorder(TreeNode* root,priority_queue<long long> &pq)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize=q.size();
            long long levelsum=0;
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
            levelsum=levelsum+q.front()->val;
            q.pop();
            }
            pq.push(levelsum);
        }
        return;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL)
        {
            return -1;
        }
        priority_queue<long long> pq;
        levelorder(root,pq);
        if(pq.size()<k)
        {
            return -1;
        }
        for(int i=1;i<k;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};
