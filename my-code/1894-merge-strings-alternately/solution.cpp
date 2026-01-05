class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.empty())
        {
            return word2;
        }
        else if(word2.empty())
        {
            return word1;
        }
        string ans;
        int p1=0;
        int p2=0;
        while(p1<word1.size() || p2<word2.size())
        {
            if(p1>=word1.size())
            {
              ans.push_back(word2[p2]);
              p2++;
            }
            else if(p2>=word2.size())
            {
                ans.push_back(word1[p1]);
                p1++;
            }
            else
            {
                ans.push_back(word1[p1]);
                ans.push_back(word2[p2]);
                p1++;
                p2++;
            }
        }
        return ans;
    }
};
