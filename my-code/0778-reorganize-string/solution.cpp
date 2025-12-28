class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push({it->second,it->first});
        }
        m.clear();
        pair<int,char> prev={0,' '};
        while(!pq.empty() || prev.first>0)
        {
            if(pq.empty())
            {
                return "";
            }
            pair<int,char> temp=pq.top();
            ans.push_back(temp.second);
            pq.pop();
            if(prev.first>0)
            {
                pq.push(prev);
            }
            prev={temp.first-1,temp.second};
        }
        return ans;
    }
};
