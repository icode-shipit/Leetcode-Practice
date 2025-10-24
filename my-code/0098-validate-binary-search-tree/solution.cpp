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
    pair<long long,long long> validBST(TreeNode* root,bool &ans) // Assume first is max and second is min
    {
        if(root==NULL)
        {
            return{LLONG_MIN, LLONG_MAX};
        }
        pair<long long,long long> leftpair= validBST(root->left,ans); 
        pair<long long,long long> rightpair= validBST(root->right,ans);
        
        pair<long long, long long> newpair; // Node to be returned in each node level

        // Lets first write code for returning pair which has max,min vals in the current tree
        long long maxval=max(leftpair.first,rightpair.first);

            if(maxval<(long long)root->val)
            {
                newpair.first=root->val;
            }
            else
            {
                newpair.first=maxval;
            }

        long long minval=min(leftpair.second,rightpair.second);

            if(minval>(long long)root->val)
            {
                newpair.second=root->val;
            }
            else
            {
                newpair.second=minval;
            }
        
        //Now lets check BST conditions
        if(leftpair.first >= (long long)root->val)
        {
            ans=false;
        }

        if(rightpair.second <= (long long) root->val)
        {
            ans=false;
        }

        return newpair; 

    }

    bool isValidBST(TreeNode* root) {
        bool ans=true;
        pair<long long,long long> maxmin= validBST(root,ans);
        return ans;  
    }
};
