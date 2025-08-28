class Solution {
public:


int catalan(int n,unordered_map <int,int> &m)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    int total=0;

    if(n%2==0)
    {
    for(int i=0;i<n/2;i++)
    {
        if(m[i]!=0 || m[n-i-1]!=0)
        {
            if(m[i]==0)
            {
                total=total+catalan(i,m)*m[n-i-1];
            }
            else if(m[n-i-1]==0)
            {
                total=total+m[i]*catalan(n-i-1,m);
            }
            else
            {
                total=total+m[i]*m[n-i-1];
            }
        }
        else
        {
            total=total+catalan(i,m)*catalan(n-i-1,m);
        }
    }
    m[n]=total*2;
    return total*2;
    }

    else
    {
    for(int i=0;i<n/2;i++)
    {
        if(m[i]!=0 || m[n-i-1]!=0)
        {
            if(m[i]==0)
            {
                total=total+catalan(i,m)*m[n-i-1];
            }
            else if(m[n-i-1]==0)
            {
                total=total+m[i]*catalan(n-i-1,m);
            }
            else
            {
                total=total+m[i]*m[n-i-1];
            }
        }
        else
        {
            total=total+catalan(i,m)*catalan(n-i-1,m);
        }
    }
    total=total*2;
    total=total+catalan(n/2,m)*catalan(n/2,m);
    m[n]=total;
    return total;
    }
}

    int numTrees(int n) {
        unordered_map <int,int> m;
        return catalan(n,m);
    }
};
