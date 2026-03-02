class Solution {
public:
    vector<char> letters;
    string ans;
    string temp;
    int count=0;
    void backtracking(int n,char prev,int k)
    {
        if(count>=k)
        {
            return;
        }
        if(temp.size()==n)
        {
            count++;
            if(count==k)
            {
                ans=temp;
            }
            return;
        }
        for(int i=0;i<letters.size();i++)
        {
            if(prev=='0')
            {
                temp.push_back(letters[i]);
            }
            else
            {
                if(letters[i]==prev)
                {
                    continue;
                }
                else
                {
                    temp.push_back(letters[i]);
                }
            }
            backtracking(n,letters[i],k);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        letters.push_back('a');
        letters.push_back('b');
        letters.push_back('c');
        backtracking(n,'0',k);
        return ans;
    }

};
