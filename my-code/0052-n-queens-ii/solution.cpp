class Solution {
public:
    int ans;
    unordered_set<int> col;
    unordered_set<int> posdiag;
    unordered_set<int> negdiag;
    void backtracking(int r,int n)
    {
        if(r==n)
        {
            ans++;
            return;
        }

        for(int c=0;c<n;c++)
        {
            if(col.contains(c) || posdiag.contains(r+c) || negdiag.contains(r-c))
            {
                continue;
            }
            col.insert(c);
            posdiag.insert(r+c);
            negdiag.insert(r-c);

            backtracking(r+1,n);

            col.erase(c);
            posdiag.erase(r+c);
            negdiag.erase(r-c);
        }
        return;
    }
    int totalNQueens(int n) {
        backtracking(0,n);
        return ans;
    }
};
