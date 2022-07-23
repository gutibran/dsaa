class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # create a hash map to hold a map of numbers
        hash_map = {}
        
        # add all the keys from 0 to n (length of the given nums array) plus 1
        for i in range(len(nums) + 1):
            # add a key and set its value to 0
            hash_map[i] = 0
            
        # iterate through the numbers and and add to the hash map if it exists
        for num in nums:
            if num in hash_map:
                hash_map[num] += 1
        
        # iterate through the hash map and return the key that has a value of 0
        for key, value in hash_map.items():
            if value == 0:
                return key