class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int area;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            area=(j-i)*min(height[i],height[j]);
            if(area>maxarea)
            {
                maxarea=area;
            }
            if(height[i]<height[j])
            {
                i++;
                continue;
            }
            else if(height[i]>height[j])
            {
               j--;
               continue;
            }
            else if(height[i]==height[j])
            {
               if(height[i+1]>height[j-1])
               {
                  i++;
               }
               else
               {
                j--;
               }
            }
        }
        return maxarea;
    }
};
