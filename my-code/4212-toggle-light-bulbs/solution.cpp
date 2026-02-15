class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        sort(bulbs.begin(),bulbs.end());
        vector<int> ans;
        for(int i=0;i<bulbs.size();i++)
        {
            if(i==bulbs.size()-1)
            {
                ans.push_back(bulbs[i]);
                break;
            }
            else if(bulbs[i]!=bulbs[i+1])
            {
                ans.push_back(bulbs[i]);
                continue;
            }
            bool state=0;
            while(i<bulbs.size()-1 && bulbs[i]==bulbs[i+1])
            {
                state=!state;
                i++;
            }
            state=!state;
            if(state==1)
            {
                ans.push_back(bulbs[i]);
            }
            if(i==bulbs.size()-1)
            {
                break;
            }
        }
        return ans;
    }
};
