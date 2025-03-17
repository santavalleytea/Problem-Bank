#include <iostream>
#include <vector>
#include <unordered_map>

// LeetCode #167

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            unordered_map<int, int> map;
    
            for (int i = 0; i < numbers.size(); ++i) {
                int delta = target - numbers[i];
    
                if (map.find(delta) != map.end()) {
                    return {map[delta], i+1};
                }
                
                map[numbers[i]] = i+1;
            }
    
            return {};
        }
    };