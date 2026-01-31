class Solution {
public:
    string reverseByType(string s) {
        string temp;
        vector<char> v1;
        vector<int> v2;
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                temp.push_back(s[i]);
            }
            else
            {
                v1.push_back(s[i]);
                v2.push_back(i);
            }
        }
        reverse(temp.begin(),temp.end());
        reverse(v1.begin(),v1.end());
        for(int i=0;i<v2.size();i++)
        {
            temp.insert(v2[i],1,v1[i]);
        }
        return temp;
    }
};
