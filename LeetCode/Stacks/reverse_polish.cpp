#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// LeetCode 150

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> st;
    
            for (int i = 0; i < tokens.size(); ++i) {
                // isdigit only works on single characters
                // tokens[i].size() > 1 for negative numbers
                if (isdigit(tokens[i].back()) || tokens[i].size() > 1) {
                    st.push(stoi(tokens[i]));
                    continue;
                } else {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
    
                    /*
                        Switch only works for char or ints !!
                        tokens[i][0] is a char whereas tokens[i] a string
                    */ 
                    switch(tokens[i][0]) {
                        case '+':
                            st.push(b + a);
                            break;
                        case '-':
                            st.push(b - a);
                            break;
                        case '*':
                            st.push(b * a);
                            break;
                        case '/':
                            st.push(b / a);
                            break;
                    }
                }
            }
    
            return st.top();
        }
    };