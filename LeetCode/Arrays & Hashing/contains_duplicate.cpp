#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            // Unordered set with unique elements
            std::unordered_set<int> vals;
    
            for (int i = 0; i < nums.size(); ++i) {
                if (vals.find(nums[i]) != vals.end()) {
                    return true;
                } else {
                    vals.insert(nums[i]);
                }
            }
    
            return false;
        }
    };