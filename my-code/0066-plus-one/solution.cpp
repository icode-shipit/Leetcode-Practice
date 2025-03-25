class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int temp = digits.size() - 1;
        int q = digits.size() - 1;
        int p = digits[q];
        if (p < 9) {
            digits[q]++;
            return digits;
        }
        while (digits[q] == 9) {
            if (q == 0 ) {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            } else {
                digits[q] = 0;
                if (digits[q - 1] < 9) {
                    digits[q - 1]++;
                    break;
                }
                q--;
            }
        }
        return digits;
    }
};
