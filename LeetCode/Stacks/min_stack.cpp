#include <iostream>
#include <vector>

using namespace std;

// LeetCode 155

class MinStack {
    private:
        // Initialize stack and min stack
        vector<int> st;
        vector<int> minStack;
    public:
        MinStack() {}
        
        void push(int val) {
            // Push val to stack and push to min stack (if empty or val smaller)
            st.push_back(val);
            if (minStack.empty() || val <= minStack.back()) {
                minStack.push_back(val);
            } else {
                // To avoid heap overflow; if val >= .back(), duplicate the current .back() value and push
                // This avoids mismatch between st and minStack
                minStack.push_back(minStack.back());
            }
        }
        
        // Pop back to remove the last element in both vectors
        void pop() {
            st.pop_back();
            minStack.pop_back();
        }
        
        // Return last element of stack
        int top() {
            return st.back();
        }
        
        // Return last element of min stack
        int getMin() {
            return minStack.back();
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */