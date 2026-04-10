class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    unordered_set<int> s;
    void backtracking(int k,int target,int p,int curr_sum)
    {
        if(curr_sum==target && k==0)
        {
            res.push_back(temp);
            return;
        }
        if(curr_sum>target || k<0 || p>9)
        {
            return;
        }
        temp.push_back(p);
        backtracking(k-1,target,p+1,curr_sum+p);
        temp.pop_back();
        backtracking(k,target,p+1,curr_sum);
    }  
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45 || n<3)
        {
            return {};
        }
        backtracking(k,n,1,0);
        return res;
    }
};
