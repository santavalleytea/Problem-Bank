#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


class Solution {
    public:
        std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
            std::unordered_map<int, int> map;
    
            // Iterate through array and store num-frequency pair in map
            for (int i = 0; i < nums.size(); ++i) {
                map[nums[i]]++;
            }
    
            // Initialize max heap; pair<int,int> to store both in one 
            std::priority_queue<std::pair<int,int>> maxHeap;
    
    
            // Iterate through map and push the values by descending frequency
            for (auto [num, freq] : map) {
                maxHeap.push({freq, num});
            }
    
            std::vector<int> result;
    
            // Iterate k times and append top value (frequency) to result array
            for (int i = 0; i < k; ++i) {
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
    
            return result;
        }
    };