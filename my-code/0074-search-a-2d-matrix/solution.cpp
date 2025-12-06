class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0]>target)
        {
            return false;
        }
        if(matrix[0][0]==target)
        {
            return true;
        }
        int maxrows=matrix.size();
        int maxcols=matrix[0].size();

        int rs=0;
        int re=maxrows-1;
        while(rs<=re)
        {
            int mid=(rs+re)/2;
            if(matrix[mid][0]<target)
            {
                rs=mid+1;
            }
            else if(matrix[mid][0]>target)
            {
                re=mid-1;
            }
            else if(matrix[mid][0]==target)
            {
                return true;
            }
        }
        int cs=0;
        int ce=maxcols-1;
        while(cs<=ce)
        {
            int mid=(cs+ce)/2;
            if(matrix[re][mid]<target)
            {
                cs=mid+1;
            }
            else if(matrix[re][mid]>target)
            {
                ce=mid-1;
            }
            else if(matrix[re][mid]==target)
            {
                return true;
            }
        }
        return false;
    }
};
