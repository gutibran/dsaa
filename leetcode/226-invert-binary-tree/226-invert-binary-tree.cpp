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
    void homebrew(TreeNode* root) {
        // base case
        if (!root) {
            return;
        }
        
        // crate an TreeNode object to hold onto one of the nodes that gets replaced during the swapping
        TreeNode* t;
        
        // traverse down the left and right sub-trees
        invertTree(root->left);
        invertTree(root->right);
        
        // swap the nodes
        t = root->left;
        root->left = root->right;
        root->right = t;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        homebrew(root);
        return root;
    }
};