#include <iostream>
#include <vector>

using namespace std;

// LeetCode #11

class Solution {
    public:
        int maxArea(vector<int>& height) {
            // Initialize to 0 to avoid garbage value
            int maxA = 0;
            int left = 0;
            int right = height.size() - 1;
    
            while (left < right) {
                int width = right - left;
    
                // Determine max area
                maxA = max(maxA, min(height[left], height[right]) * width);
    
                if (height[left] <= height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
    
            return maxA;
        }
    };