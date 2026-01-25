class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;
        vector<pair<int,int>> neg;
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i]>=0)
             {
                 temp.push_back(nums[i]);
             }
            else
             {
                 neg.push_back({nums[i],i});
             }
        }
        if(temp.empty())
        {
            return nums;
        }
        // now rotate temp array by k time left
        k=k%temp.size();
        // while(k>0)
        //     {
        //         int ran=temp[0];
        //         temp.erase(temp.begin());
        //         temp.push_back(ran);
        //         k--;
        //     }
        rotate(temp.begin(), temp.begin() + k, temp.end());
        for(auto it=neg.begin();it!=neg.end();it++)
        {
            temp.insert(temp.begin()+it->second,it->first);
        }
        return temp;
    }
};
