int removeElement(int* nums, int numsSize, int val) 
{
    int count=0;
  for(int i=0;i<numsSize;i++)
  {
    if(nums[i]==val)
    {
        count++;
    }
  }
  int n=numsSize-count;
  if(n==0)
  {
    return 0;
  }
  char s[n];
  int b=0;
  for(int i=0;i<numsSize;i++)
  {
     if(nums[i]!=val)
     {
        s[b]=nums[i];
        b++;
     }
  }
  for(int i=0;i<n;i++)
  {
    nums[i]=s[i];
  }
  return n;
}
