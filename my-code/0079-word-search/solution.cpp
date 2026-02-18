class Solution {
public:
    // set<pair<int,int>> s;
    bool dfs(vector<vector<char>>& board, string& word,int p,int r,int c)
    {
        if(p==word.size())
        {
            return true;
        }
        else if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='#' || word[p]!=board[r][c])
        {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';   // mark visited

        bool res = dfs(board,word,p+1,r+1,c) ||
                   dfs(board,word,p+1,r-1,c) ||
                   dfs(board,word,p+1,r,c+1) ||
                   dfs(board,word,p+1,r,c-1);

        board[r][c] = temp;  // backtrack
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
               if(dfs(board,word,0,i,j)==true)
               {
                return true;
               }
            }
        }
        return false;
    }
};
