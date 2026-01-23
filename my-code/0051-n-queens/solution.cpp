class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> posdiag;
    unordered_set<int> negdiag;
    vector<vector<string>> ans;
    void Backtracking(int r,vector<string> &board,int n)
    {
        if(r==n)
        {
            vector<string> copy=board;
            ans.push_back(copy);
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(col.contains(c) || posdiag.contains(r+c) || negdiag.contains(r-c))
            {
                continue;
            }
            board[r][c]='Q';
            col.insert(c);
            posdiag.insert(r+c);
            negdiag.insert(r-c);

            Backtracking(r+1,board,n);

            board[r][c]='.';
            col.erase(c);
            posdiag.erase(r+c);
            negdiag.erase(r-c);
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i=0;i<n;i++)
        {
            string temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back('.');
            }
            board.push_back(temp);
        } // upto here board is made
        Backtracking(0,board,n);
        return ans;
    }
};
