class Solution {
public:
    unordered_set<int> used; // used numbers in range
    bool backtracking(vector<int>& res,int p,int prev,int n)
    {
        if(p==0)
        {
            int diff = res[0] ^ res[1];
            return diff > 0 && (diff & (diff - 1)) == 0;
        }
        int curr_val;
        for(int i=0;i<n;i++)
        {
            curr_val= prev^(1<<i);
            if(used.contains(curr_val)) continue;
            res[p]=curr_val;
            used.insert(curr_val);
            if(backtracking(res,p-1,curr_val,n)==true)
            {
                return true;
            }
            used.erase(curr_val);
        }
        return false;
    }
    vector<int> grayCode(int n) {
        vector<int> res((1 << n));
        res[0]=0;
        used.insert(0);
        bool rand=backtracking(res,(1<<n)-1,0,n);
        return res;
    }
};
