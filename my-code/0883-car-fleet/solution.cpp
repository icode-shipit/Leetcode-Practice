class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int> m;
        for(int i=0;i<position.size();i++)
        {
           m[position[i]]=i;
        }
        sort(position.begin(),position.end());
        stack<pair<int,int>> s;
        for(int i=0;i<position.size();i++)
        {
          s.push({m[position[i]],position[i]});  
        }

        pair<int,int> toppair=s.top();
        double timetop=double(target-toppair.second)/double(speed[toppair.first]);
        s.pop(); 

        int fleetno=1;
        while(!s.empty())
        {
          pair<int,int> nextpair=s.top();
          double timenext=double(target-nextpair.second)/double(speed[nextpair.first]);  
          if(timetop<timenext)
          {
            fleetno++;
            timetop=timenext;
            s.pop();
          } 
          else
          {
            s.pop();
            continue;
          }
        }
        return fleetno;
    }
};
