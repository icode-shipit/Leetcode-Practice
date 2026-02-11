class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l=0;
        int r=0;
        int n=colors.size();
        int ans=0;
        int count=0;
        while(count<n+k-1)
        {
            count++;
        //    if(r==0 && l==0)
        //    {
        //     r=(r+1)%n;
        //    }
        //    else 
        if(colors[r]!=colors[(r - 1 + n) % n])
           {
            if(((r - l + n) % n + 1) == k)
            {
               ans++;
               l=(l+1)%n;
            }
            r=(r+1)%n;
           }
           else
           {
            l=r;
            r=(r+1)%n;
           }
        }
        return ans;
    }
};
