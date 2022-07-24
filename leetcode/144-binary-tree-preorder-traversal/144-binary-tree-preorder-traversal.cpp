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
    // hold the result
    vector<int> result;
    
    // helper function
    void pt(TreeNode* root) {
        // base case
        if (!root) {
            return;
        }
        
        // add the current node the vector
        result.push_back(root->val);
        
        
        // traverse down the left sub-tree
        pt(root->left);
        
        // traverse down the right sub-tree
        pt(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        // compute the resulting vector
        pt(root);
        
        // return the resulting vector
        return result;
    }
};