/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int min=1;
        int max=n;
        int ans=max;
        while(min<=max)
        {
            int mid=min+(max-min)/2;
            int gv=guess(mid);
          if(gv==0)
          {
            return mid;
          }
          else if(gv==-1)
          {
            max=mid-1;
          }
          else
          {
            min=mid+1;
          }
        }
        return ans;
    }
};
