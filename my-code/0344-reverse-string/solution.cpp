class Solution {
public:
    void reverseString(vector<char>& s) {
        int i1=0;
        int i2=s.size()-1;
        while(i1<i2)
        {
           swap(s[i1],s[i2]);
           i1++;
           i2--;
        }
        return ;
    }
};
