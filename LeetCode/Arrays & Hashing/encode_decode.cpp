#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Codec {
    public:
    
        // Encodes a list of strings to a single string.
        string encode(vector<string>& strs) {
            string val = "";
            for (int i = 0; i < strs.size(); ++i) {
                // Set the length + '!' as the delimiter
                val += to_string(strs[i].length()) + "!" + strs[i];
            }
    
            return val;
        }
    
        // Decodes a single string to a list of strings.
        vector<string> decode(string s) {
            vector<string> result;
            
            int i = 0;
            while (i < s.size()) {
                int j = i;
                // Find the delimiter
                while (s[j] != '!') {
                    j++;
                }
    
                // Find the length of string i
                int len = stoi(s.substr(i, j - i));
                // Extract the word starting after the delimitter to the end of string length
                string word = s.substr(j + 1, len);
    
                result.push_back(word);
    
                // Move to the start of the next word
                i = j + 1 + len;
            }
    
            return result;
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec codec;
    // codec.decode(codec.encode(strs));