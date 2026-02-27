class TrieNode{
    public:
    char ch;
    vector<TrieNode*> childnodes;
    bool end;
    TrieNode()
    {
        end=false;
    }
    void addWord(string& word)
    {
        TrieNode* cur=this;
        for(int i=0;i<word.size();i++)
        {
            bool found = false;
            for(int j=0;j<cur->childnodes.size();j++)
            {
            if(cur->childnodes[j]->ch==word[i])
            {
                cur=cur->childnodes[j];
                found=true;
                break;
            }
            }
           if(!found)
           {
              TrieNode* newnode = new TrieNode();
              newnode->ch=word[i];
              cur->childnodes.push_back(newnode);
              cur=newnode;
           }
        }
        cur->end=true;
    }
};

class Solution {
public:
    vector<string> ans;
    string temp;
    void dfs(vector<vector<char>>& board,int r,int c,TrieNode* cur)
    {
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='#')
        {
            return ;
        }
        bool found=false;
        for(int i=0;i<cur->childnodes.size();i++)
        {
            if(cur->childnodes[i]->ch==board[r][c])
            {
                found=true;
                cur=cur->childnodes[i];
                break;
            }
        }
        if(!found)
        {
            return ;
        }
        char temp1=board[r][c];
        temp.push_back(temp1);
        if(cur->end==true)
        {
            cur->end=false;
            ans.push_back(temp);
        }
        board[r][c]='#';
        dfs(board,r+1,c,cur); dfs(board,r-1,c,cur); dfs(board,r,c+1,cur); dfs(board,r,c-1,cur);
        board[r][c]=temp1;
        temp.pop_back();
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie=new TrieNode();
        for(int i=0;i<words.size();i++)
        {
           trie->addWord(words[i]);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                dfs(board,i,j,trie);
            }
        }
        return ans;
    }
};
