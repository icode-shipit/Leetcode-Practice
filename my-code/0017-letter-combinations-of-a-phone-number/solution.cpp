class Solution {
public:
    vector<string> ans;
    string temp;
    unordered_map<char,vector<char>> m;
    void makemap()
    {
        m['2'].insert(m[2].end(),{'a','b','c'});
        m['3'].insert(m[3].end(),{'d','e','f'});
        m['4'].insert(m[4].end(),{'g','h','i'});
        m['5'].insert(m[5].end(),{'j','k','l'});
        m['6'].insert(m[6].end(),{'m','n','o'});
        m['7'].insert(m[7].end(),{'p','q','r','s'});
        m['8'].insert(m[8].end(),{'t','u','v'});
        m['9'].insert(m[9].end(),{'w','x','y','z'});
    }
    void backtracking(string& digits,int p)
    {
        if(p==digits.size())
        {
           ans.push_back(temp);
           return;
        }
        for(int i=0;i<m[digits[p]].size();i++)
        {
           temp.push_back(m[digits[p]][i]);
           backtracking(digits,p+1);
           temp.pop_back();
        } 
    }
    vector<string> letterCombinations(string digits) {
        makemap();
        backtracking(digits,0);
        return ans;
    }
};
