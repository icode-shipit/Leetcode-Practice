class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    string temp = "";
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        // Check if s[i] is already in temp
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] == s[i]) {
                // Remove everything up to the duplicate
                temp = temp.substr(j + 1);
                break;
            }
        }

        temp += s[i]; // Add current character
        if (temp.length() > maxLen) {
            maxLen = temp.length();
        }
    }

    return maxLen;
}

};
