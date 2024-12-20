bool isPalindrome(int x) {
    int count=0; 
    int n=x;
    if(x<0)
    {
        return false;
    }
    if(x<10)
    {
        return true;
    }
    int p=0;
    while(n>0)
    {
       n=n/10;
       p++;
    }
    int b[p];
    if(x>=10)
    {
        while(x>0)
        {
            b[count]=x%10;
            x=x/10;
            count++;
        }
    }
    int c[count];
    for(int i=0;i<count;i++)
    {
        c[i]=b[count-i-1];
    }
    for(int i=0;i<count;i++)
    {
        if(b[i]!=c[i])
        {
            return false;
        }
        if(i==count-1)
        {
            return true;
        }
    }
    return 0;
}
