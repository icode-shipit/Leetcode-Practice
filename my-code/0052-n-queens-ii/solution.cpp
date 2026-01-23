class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> col;
    unordered_set<int> posdiag;
    unordered_set<int> negdiag;
    void backtracking(int r,int n,vector<string> &board)
    {
        if(r==n)
        {
            vector<string> copy= board;
            ans.push_back(board);
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

            backtracking(r+1,n,board);

            board[r][c]='.';
            col.erase(c);
            posdiag.erase(r+c);
            negdiag.erase(r-c);
        }
        return;
    }
    int totalNQueens(int n) {
        vector<string> board;
        for(int i=0;i<n;i++)
        {
            string temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back('.');
            }
            board.push_back(temp);
        }
        backtracking(0,n,board);
        return ans.size();
    }
};
