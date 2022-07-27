class Solution {
public:
    bool isPalindrome(int x) {
        // edge case
        if (x < 0) {
            return false;
        }
        // define a vector to hold the digits
        vector<int> digits;
        
        // truncate digits till the given number becomes zero
        while (x != 0) {
            digits.push_back(x % 10);
            x = floor(x / 10);
        }
        
        // iterate from both ends of the array till n / 2
        size_t j = digits.size() - 1;
        for (size_t i = 0; i < ceil(digits.size() / 2); i++) {
            cout << digits[i] << " == " << digits[j] << endl;
            if (digits[i] != digits[j]) {
                return false;
            }
            j -= 1;
        }
        
        return true;
    }
};