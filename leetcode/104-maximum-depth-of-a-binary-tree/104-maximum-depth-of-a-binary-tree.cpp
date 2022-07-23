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
    int maxDepth(TreeNode* root) {
        // base case
        if (!root) {
            return 0;
        } 
        
        // determine the depth for the left and right sub-trees
        int left_sub_tree_depth = maxDepth(root->left);
        int right_sub_tree_depth = maxDepth(root->right);
        
        // return the greater depth value of the two while coming back up from recursive calls
        if (left_sub_tree_depth > right_sub_tree_depth) {
            return left_sub_tree_depth + 1;
        }
        return right_sub_tree_depth + 1;
    }
};