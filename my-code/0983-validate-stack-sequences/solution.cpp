class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p1=0;
        int p2=0;
        while(p1<pushed.size() || p2<popped.size())
        {
            if(!s.empty())
            {
                if(popped[p2]==s.top())
                {
                    s.pop();
                    p2++;
                }
                else if(s.top()!=popped[p2] && p1>=pushed.size())
                {
                    return false;
                }
                else
                {
                    s.push(pushed[p1]);
                    p1++;
                }
            }
            else
            {
                s.push(pushed[p1]);
                p1++;
            }
        }
        if(s.empty())
        {
            return true;
        }
        return false;
    }
};
