/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // define a class member to hodl the sum
    int sum = { 0 };
    
    // modified pre-order traversal
    void pre_order(TreeNode* node, int low, int high) {
        // base case for if the node is null
        if (!node) {
            // break out of the current recursive call and go back to the previous one
            return;
        }
        
        // check if the current node's value fits within the given range
        if (node->val >= low && node->val <= high) {
            this->sum += node->val;         
        }
        
        // traverse down the left sub-tree
        pre_order(node->left, low, high);
        
        // traverse down the right sub-tree
        pre_order(node->right, low, high);
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        // run the modified pre-order traversal to determine the sum
        pre_order(root, low, high);
        
        // return the class member that is holding the sum
        return this->sum;
    }
};