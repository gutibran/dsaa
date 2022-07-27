// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // binary search
    int firstBadVersion(int n) {
        // define the search space
        size_t low = 1;
        size_t high = n;
        size_t middle; 
        
        vector<int> badVersions;
        
           
        while (low <= high) {
            // determine the middle number
            middle = floor((low + high) / 2);
            
            // check if the middle element is the bad version
            if (isBadVersion(middle)) {
                badVersions.push_back(middle);
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        
        // find the minimum element in the vector
        size_t m = numeric_limits<int>::max();
        for (size_t i = 0; i < badVersions.size(); i++) {
            if (badVersions[i] < m) {
                m = badVersions[i];
            }
        }
        
        cout << m << endl;
        return m;
        
        
    }
};