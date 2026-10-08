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
    int helper(TreeNode* node,int & maxi){
        if(node==NULL) return 0;
        int leftgain=max(0,helper(node->left,maxi));
        int rightgain=max(0,helper(node->right,maxi));
        maxi=max(maxi,node->val+leftgain+rightgain);
        return (node->val)+max(leftgain,rightgain);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};