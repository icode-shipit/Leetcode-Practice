class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void backtracking(int n, int k,int i)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        if(temp.size()>k)
        {
            return;
        }
        for(int j=i;j<=n;j++)
        {
            temp.push_back(j);
            backtracking(n,k,j+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return ans;
    }
};
