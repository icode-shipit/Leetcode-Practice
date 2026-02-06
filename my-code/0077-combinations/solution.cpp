class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtracking(int n,int k,int i)
    {
        if(temp.size()==k)
        {
          ans.push_back(temp);
          return; 
        }
        else if(temp.size()>k || i>n)
        {
            return;
        }
        else
        {
            temp.push_back(i);
            backtracking(n,k,i+1);
            temp.pop_back();
            backtracking(n,k,i+1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return ans;
    }
};
