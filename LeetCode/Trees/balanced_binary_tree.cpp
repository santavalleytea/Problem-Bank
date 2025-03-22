#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int check(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
    
            int left = check(root->left);
            // Won't run until second lowest node onwards, since last will just be (0, 0)
            if (left == -1) {
                return -1;
            }
    
            int right = check(root->right);
            if (right == -1) {
                return -1;
            }
    
            // Check to see if the height differs by more than one on right and left
            if (abs(right - left) > 1) {
                return -1;
            }
    
            // Return the max depth to the current root 
            return 1 + max(right, left);
        }
    
        bool isBalanced(TreeNode* root) {
            return check(root) != -1;
        }
    };
    
    /*
    check(1)
    ├── check(2)
    │   ├── check(4)
    │   │   ├── check(nullptr) → returns 0 
    │   │   └── check(nullptr) → returns 0 
    │   │   → height of 4 = 1 + max(0, 0) = 1 
    │   → check(2)'s right child is nullptr → returns 0 
    │   → height of 2 = 1 + max(1, 0) = 2 
    ├── check(3)
    │   ├── check(nullptr) → returns 0 
    │   └── check(nullptr) → returns 0 
    │   → height of 3 = 1 + max(0, 0) = 1 
    → height of 1 = 1 + max(2, 1) = 3 which not equal to -1 
    */