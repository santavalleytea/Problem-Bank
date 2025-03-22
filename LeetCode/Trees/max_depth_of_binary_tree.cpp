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
        int maxDepth(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
    
            // Recursively compute max depth of left and right subtree
            int maxD = max(maxDepth(root->left), maxDepth(root->right));
            
            // Add 1 to maxD to compute depth of root above
            return 1 + maxD;
        }
    };
    
    
    /*
    Example: max(maxDepth(5), maxDepth(20)) => max(null, null) and max(maxDepth(15), maxDepth(17))
    maxDepth(5) = 1 + 0 and maxDepth(20) = 1 + max(1, 1) = 2
    maxDepth(3) = 1 + max(2, 1) = 3
    */