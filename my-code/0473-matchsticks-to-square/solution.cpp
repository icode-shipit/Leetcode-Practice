class Solution {
public:
    vector<int> v={0,0,0,0}; // l,t,r,b
    bool backtracking(vector<int>& matchsticks,int i,int len)
    {
        if(i==matchsticks.size())
        {
            return true;
        }
        for(int j=0;j<v.size();j++)
        {
            if(matchsticks[i]+v[j]<=len) // then that means we can put matchstick and check further possib
            {
                v[j]+=matchsticks[i];
                if(backtracking(matchsticks,i+1,len)==true)
                {
                    return true;
                }
                v[j]-=matchsticks[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(), matchsticks.rend());
        int total_sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total_sum%4!=0)
        {
            return false;
        }
        return backtracking(matchsticks,0,total_sum/4); //matchsticks,i
    }
};
