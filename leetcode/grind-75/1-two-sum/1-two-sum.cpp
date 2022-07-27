#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a hash map
        std::map<int, int> hash_map;
        
        // create a vector to hold the indices
        std::vector<int> result;
        
        // iterate through the numbers
        for (size_t i = 0; i < nums.size(); i++) {
            // check if the absolute value of the differrence of the current number and targets exist
            if (hash_map.count(target - nums[i])) {
                // push the current numbers index
                result.push_back(i);
                
                // push the other numbers index
                result.push_back(hash_map[target - nums[i]]);
            }
            hash_map[nums[i]] = i;
        }
        
        return result;
    }
};