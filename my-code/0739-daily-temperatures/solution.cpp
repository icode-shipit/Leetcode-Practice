class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<pair<int,int>> s;
        for(int i=0;i<temperatures.size();i++)
        {
          if(s.empty())
          {
            s.push({i,temperatures[i]});
            continue;
          }
          while(!s.empty())
          {
          if(s.top().second<temperatures[i])
          {
            answer[s.top().first]=i-s.top().first;
            s.pop();
          }
          else
          {
            s.push({i,temperatures[i]});
            break;
          }
          }
          s.push({i,temperatures[i]});
        }
        return answer;
    }
};
