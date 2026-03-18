class Solution {
public:
    unordered_set<string> s1;
    int ans=INT_MIN;
    int curr_size=0;
    void backtracking(string& s,int l)
    {
        if(l==s.size())
        {
           ans=max(ans,curr_size);
           return;
        }
        for(int r=l;r<s.size();r++)
        {
            string curr=s.substr(l,r-l+1);
            if(!s1.contains(curr))
            {
                s1.insert(curr);
                curr_size++;
                backtracking(s,r+1);
                s1.erase(curr);
                curr_size--;
            }
        }
        return;
    } 
    int maxUniqueSplit(string s) {
        backtracking(s,0);
        return ans;
    }
};
