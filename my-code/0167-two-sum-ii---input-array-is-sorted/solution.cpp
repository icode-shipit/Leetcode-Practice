class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       vector<int> ans;
       int i1=0;
       int i2=numbers.size()-1; 
       while(i1<i2)
       {
        if(numbers[i1]+numbers[i2]>target)
        {
           i2--;
        }
        else if(numbers[i1]+numbers[i2]<target)
        {
            i1++;
        }
        else if(numbers[i1]+numbers[i2]==target)
        {
            ans.push_back(i1+1);
            ans.push_back(i2+1);
            break;
        }
       }
       return ans;
    }
};
