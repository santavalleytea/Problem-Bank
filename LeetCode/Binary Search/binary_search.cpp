#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            if (nums.empty()) {
                return -1;
            }
    
            int left = 0;
            int right = nums.size() - 1;
    
            while (left <= right) {
                // Make sure to add left since left can be > 0
                int mid = left + ((right - left) / 2);
    
                if (nums[mid] > target) {
                    right = mid - 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    return mid;
                }
            }
    
            return -1;
        }
    };