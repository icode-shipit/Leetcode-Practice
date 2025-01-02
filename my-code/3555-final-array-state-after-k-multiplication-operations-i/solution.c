/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    int count=0;
    while(count<k)
    {
        int b=0;
        int p=nums[0];
        for(int i=0;i<numsSize;i++)
        {
            if(p>nums[i])
            {
                p=nums[i];
                b=i;
            }
        }
        nums[b]=nums[b]*multiplier;
        count++;
    }
     *returnSize = numsSize;
    int* result = malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
       result[i]=nums[i]; 
    } 
    return result;
}
