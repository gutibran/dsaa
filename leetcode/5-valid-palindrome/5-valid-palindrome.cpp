#include <vector>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        // singletonian ableton
       if (s.size() == 1) {
           return true;
       }
        
        // the processed string
        vector<char> result;
        
        // iterate through the characters
        // does not push any non-alphanumerics or whitespace
        for (size_t i = 0; i < s.size(); i++) {
            // check if the characters is alpha numeric
            if (isalpha(s[i]) || isdigit(s[i])) {
                // push the lower case version
                result.push_back(tolower(s[i]));
            }
        }
        
        // iterate from the start and end
        int i = 0;
        int j = result.size() - 1;
        while (i < floor(result.size() / 2)) {
            // check for mismatch
            if (result[i] != result[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        // if there is no mismatch return true;
        return true;
    }
};