class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x<0):
            return False
        else:
            y= len(str(x))
            z=str(x)
            for i in range(y//2):
                if(z[i]!=z[y-i-1]):
                    return False
            return True



