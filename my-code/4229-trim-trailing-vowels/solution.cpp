class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> vow;
        vow.insert({'a','e','i','o','u'});
        for(int i=s.size()-1;i>=0;i--)
            {
                if(!vow.contains(s[i]))
                {
                    break;
                }
                else
                {
                    int j=i-1;
                    while(j>=0 && vow.contains(s[j]))
                        {
                            j--;
                        }
                    j++;
                    s.erase(j,i-j+1);
                    break;
                }
            }
        return s;
    }
};
