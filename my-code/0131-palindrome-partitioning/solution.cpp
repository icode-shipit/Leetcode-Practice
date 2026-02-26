class Solution {
public:
    vector<string> temp;
    vector<vector<string>> ans;
    bool palindrome(string& s,int i,int j)
    {
        int l=i;
        int r=j;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtracking(int i,string& s)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(palindrome(s,i,j)==true)
            {
                temp.push_back(s.substr(i,j-i+1));
                backtracking(j+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(0,s);
        return ans;
    }
};

