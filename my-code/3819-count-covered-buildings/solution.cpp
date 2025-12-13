class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // we have to group nodes with same x values and sort them in ascending order and store somewhre
        // similarly group nodes with same y value then nodes in bw first and last 
        // and find common nodes and count them and return value
        
        vector<pair<int,int>> vx(n+1,{INT_MAX, INT_MIN});
        vector<pair<int,int>> vy(n+1,{INT_MAX, INT_MIN});
        for(int i=0;i<buildings.size();i++)
        {
          // first lets store {min y,max y} for particular x value in node
          int min_y= min(vx[buildings[i][0]].first,buildings[i][1]);
          int max_y= max(vx[buildings[i][0]].second,buildings[i][1]);
          vx[buildings[i][0]].first=min_y;
          vx[buildings[i][0]].second=max_y;

          //similarly lets store {min x,max x} for a particular y value
          int min_x= min(vy[buildings[i][1]].first,buildings[i][0]);
          int max_x= max(vy[buildings[i][1]].second,buildings[i][0]);
          vy[buildings[i][1]].first=min_x;
          vy[buildings[i][1]].second=max_x;
        } 

        // Now check for each node if its x val is in bw min_x,max_x for the y val of node
        // Similarly check for y val of node is in bw min_y,max_y for the x val of node
        // then return count
        int count = 0;
        for(int i=0;i<buildings.size();i++)
        {
           if(buildings[i][0]>vy[buildings[i][1]].first && buildings[i][0]<vy[buildings[i][1]].second)
           {
            if(buildings[i][1]>vx[buildings[i][0]].first && buildings[i][1]<vx[buildings[i][0]].second)
            {
                count++;
            }
           }
        }

        return count;

    }
};
