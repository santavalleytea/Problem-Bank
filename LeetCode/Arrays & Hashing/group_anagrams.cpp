#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// LeetCode #49

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // Key value i.e. aet:[eat, tea]
            unordered_map<string, vector<string>> map;
            vector<vector<string>> result;
    
            for (int i = 0; i < strs.size(); ++i) {
                // Copy of one string in strs
                string s = strs[i];
                // Sort each character in strs[i]
                sort(strs[i].begin(), strs[i].end());
                // Key: strs[i], value: s
                map[strs[i]].push_back(s);
            }
    
            // Iterate through map and store second column for each key value
            for (auto i : map) {
                result.push_back(i.second);
            }
    
            return result;
    
        }
    };
    
    // Store using unordered_map<string, vector<string>>
    // Make a copy of each strs[i] and sort original for each string
    // Return vector<vector<string>>
    
    
    // Store using unordered_map<string, vector<string>>
    // Make a copy of each strs[i] and sort original for each string
    // Return vector<vector<string>>