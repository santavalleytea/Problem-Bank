#include <iostream>
#include <vector>
#include <stack>

// LeetCode 739

using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n = temperatures.size();
            // Results vector with size n and initialize all 0s
            vector<int> result(n, 0);
            // Stack to keep track of index
            stack<int> st;
    
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    // The current index
                    int index = st.top();
                    st.pop();
                    // i - index and push that onto results at current index in temperatures
                    result[index] = i - index;
                }
    
                st.push(i);
            }
    
            return result;
        }
    };