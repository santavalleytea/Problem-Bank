#include <iostream>
#include <vector>
#include <unordered_map>

// LeetCode #1

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int>map;
    
            for (int i = 0; i < nums.size(); ++i) {
                int delta = target - nums[i];
    
                if (map.find(delta) != map.end()) {
                    return {map[delta], i};
                }
    
                map[nums[i]] = i;
            }
    
            return {};
        }
    };
    
    /**
    Naive Solution:
    - Iterate through array
    - For each element, make another iteration and check if it adds up to the target value
    - O(n^2) worst case
    
    Optimal:
    - Have a hash map with int-int pairs
    - Check the complement and see if it is in the hash
    - if it exists, return the complement and i
    - else, add it to map
    **/ 