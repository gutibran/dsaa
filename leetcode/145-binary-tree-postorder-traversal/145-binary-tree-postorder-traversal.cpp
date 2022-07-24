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
    // store the node values in a vector
    vector<int> result;
    
    // helper function
    void pt(TreeNode* root) {
        // base case
        if (!root) {
            return;
        }        
        
        // traverse down the left and right sub-trees
        pt(root->left);
        pt(root->right);
        
        // add the current node value to the resulting vector
        this->result.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        // compute the solution and return it
        pt(root);
        return result;
    }
};