class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0;i<asteroids.size();i++)
        {
          if(s.empty())
          {
            s.push(asteroids[i]);
          }
          else if(s.top()>0 && asteroids[i]<0)
          {
            if(s.top()>abs(asteroids[i]))
            {
              continue;
            }
            else if(s.top()==abs(asteroids[i]))
            {
                s.pop();
                continue;
            }
            else
            {
                while(s.top()>0 && s.top()<=abs(asteroids[i]))
                {
                    if(s.top()==abs(asteroids[i]))
                    {
                        s.pop();
                        break;
                    }
                    s.pop();
                    if(s.empty() || s.top()<0)
                    {
                      s.push(asteroids[i]);
                    }
                }
            }
          }
          else if(asteroids[i]>0 || asteroids[i]<0)
          {
            s.push(asteroids[i]);
          }
        }
        vector<int> v;
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
