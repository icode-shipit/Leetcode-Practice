class Solution {
public:
    unordered_set<int> used;
    bool backtracking(int i,int n,vector<int>& temp)
    {
        if(i==temp.size())
        {
            return true;
        }
        for(int num=n;num>0;num--)
        {
           if(used.contains(num))
           {
            continue;
           }
           if( num>1 && ((num+i)>=temp.size() || temp[num+i]!=0) )
           {
            continue;
           }
           used.insert(num);
           temp[i]=num;
           if(num>1)
           {
              temp[num+i]=num;
           }
           int j=i+1;
           while(j<temp.size() && temp[j]>0)
           {
            j++;
           }
           if(backtracking(j,n,temp)==true)
           {
            return true;
           }
           temp[i]=0;
           if(num>1)
           {
              temp[num+i]=0;
           }
           used.erase(num);
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> temp(2*n-1);
        backtracking(0,n,temp);
        return temp;
    }
};
