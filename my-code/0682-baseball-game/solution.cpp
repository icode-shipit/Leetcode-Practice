class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int i=0;
        while(i<operations.size())
        {
            if(operations[i]=="C")
            {
                if(!s.empty())
                {
                   s.pop(); 
                }
                i++;
            }
            else if(operations[i]=="D")
            {
                if(!s.empty())
                {
                    s.push(s.top()*2);
                }
                i++;
            }
            else if(operations[i]=="+")
            {
                if(s.size()>1)
                {
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(b);
                    s.push(a);
                    s.push(a+b);
                }
                i++;
            }
            else
            {
                s.push(stoi(operations[i]));
                i++;
            }
        }
        int ans=0;
        while(!s.empty())
        {
          ans=ans+s.top();
          s.pop();
        }
        return ans;
    }
};
