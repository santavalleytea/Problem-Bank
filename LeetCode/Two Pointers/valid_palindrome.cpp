#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string word;
    
            // Convert to lower case
            for (int i = 0; i < s.size(); ++i) {
                // Make sure to add numbers too
                if (s[i] >= 'a' && s[i] <= 'z' || (s[i] >= '0' && s[i] <= '9')) {
                    word += s[i];
                }  else if (s[i] >= 'A' && s[i] <= 'Z') {
                    word += (char)tolower(s[i]);
                }  
            }
    
            int left = 0;
            // Need to make sure it starts at 0 not 1
            int right = word.size() - 1;
    
            // Two pointer technique from right to left
            while (left < right) {
                if (word[left] != word[right]) {
                    return false;
                }
    
                left++;
                right--;
            }
    
            return true;
        }
    
    };