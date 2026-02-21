class Solution {
public:
    unordered_map<int,vector<int>> m;
    int dfs(int curr,int p,vector<bool>& hasApple)
    {
        int time=0;
        for(int i=0;i<m[curr].size();i++)
        {
            if(m[curr][i]==p)
            {
                continue;
            }
            int childtime=dfs(m[curr][i],curr,hasApple);
            if(childtime>0 || hasApple[m[curr][i]]==true)
            {
                time+=childtime+2;
            }
        }
        return time;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,-1,hasApple);
        //now all the parent,child relations are inserted in map
        //now lets pass it to our dfs function
    }
};
