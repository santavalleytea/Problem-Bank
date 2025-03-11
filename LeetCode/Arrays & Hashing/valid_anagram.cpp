#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            if (s.size() != t.size()) {
                return false;
            }
    
            std::unordered_map<char, int> map;
    
            for (int i = 0; i < s.size(); ++i) {
                // Add s[i] to map or increment frequency (int)
                map[s[i]]++;
            }
    
            for (int i = 0; i < t.size(); ++i) {
                // Subtract t[i] from map 
                map[t[i]]--;
                // More or different occurences between the two strings
                if (map[t[i]] < 0) {
                    return false;
                }
            }
    
            return true;
        }
    };