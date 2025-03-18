#include <iostream>
#include <stack>

using namespace std;

// LeetCode 20

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
    
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    // Push left bracket to stack
                    st.push(s[i]);
                } else {
                    // For each right bracket, check for left bracket
                    if (s[i] == ')') {
                        if (st.empty() || st.top() != '(') {
                            return false;
                        } else {
                            st.pop();
                            continue;
                        }
                    } else if (s[i] == ']') {
                        if (st.empty() || st.top() != '[') {
                            return false;
                        } else {
                            st.pop();
                            continue;
                        }
                    } else if (s[i] == '}') {
                        if (st.empty() || st.top() != '{') {
                            return false;
                        } else {
                            st.pop();
                            continue;
                        }
                    }
                }
            }
            
            // Return if stack empty
            return st.empty();
        }
    };