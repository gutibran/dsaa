class Solution {
public:
    int search(vector<int>& nums, int target) {
       // declare and initialize the low and high indicies
        int low = 0;
        int high = nums.size() - 1;
        int middle;
        
        // iterate till the search space of low and high is EXHAUSTED
        while (low <= high) {
            // determine the middle index of the current search space
            middle = floor((low + high) / 2); 
            
            // check if the middle index is the target
            if (nums[middle] == target) {
                // return the index where the target is found
                return middle;
            }
            
            // update the search space
            if (target < nums[middle]) {
                high = middle - 1;
            } else if (target > nums[middle]) {
                low = middle + 1;
            }
        }
        
        // if the control reaches here then the search space has been exhausted and not found
        return -1;
    }
};