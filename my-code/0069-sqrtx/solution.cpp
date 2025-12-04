class Solution {
public:
    int mySqrt(int x) {
        long long s=1;
        long long e=x;
        while(s<=e)
        {
            long long mid=(s+e)/2;
            long long cal=mid*mid;
            if(cal==x)
            {
                return (int)mid;
            }
            else if(cal<x)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return (int)e;
    }
};
