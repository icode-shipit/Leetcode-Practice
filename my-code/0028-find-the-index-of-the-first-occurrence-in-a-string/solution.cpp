class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        while(i<haystack.size())
        {
            while(j<needle.size() && haystack[i]==needle[j])
            {
            if(j==needle.size()-1)
            {
                return i-needle.size()+1;
            }
            j++;
            i++;
            }
            i=i-j;
            j=0;
            i++;
        }
        return -1;
    }
};
