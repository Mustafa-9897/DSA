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
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        // if the left child does not exist go to the right child
        if(!root->left) return 1+minDepth(root->right);
        
        // if the right child does not exist then go tho the left child
        if(!root->right) return 1+minDepth(root->left);

        // if both children exist the return the minimum one of the both children
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};