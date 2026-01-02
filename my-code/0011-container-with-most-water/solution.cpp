class Solution {
public:
    int maxArea(vector<int>& height) {
        long maxarea=LLONG_MIN;
        int p1=0;
        int p2=height.size()-1;
        while(p1<p2)
        {
            long curr_area=(p2-p1)*min((height[p1]),(height[p2]));
            maxarea=max(maxarea,curr_area);
            if(height[p1]<height[p2])
            {
                p1++;
            }
            else
            {
                p2--;
            }
        }
        return maxarea;
    }
};
