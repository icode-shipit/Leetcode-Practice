class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v(rowIndex+1);
        for(int i=0;i<=rowIndex;i++)
        {
            v[i].resize(i+1,0);
        }
        for(int i=0;i<=rowIndex;i++)
        {
            v[i][0]=1;
            v[i][i]=1;
        }
        if(rowIndex>=2)
        {
        for(int i=2;i<=rowIndex;i++)
        {
            for(int j=1;j<i;j++)
            {
               v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
        }
        vector<int> v1;
        int p=v[rowIndex].size();
        v1.resize(p,0);
        for(int i=0;i<p;i++)
        {
            v1[i]=v[rowIndex][i];
        }
        return v1;
    }
};
