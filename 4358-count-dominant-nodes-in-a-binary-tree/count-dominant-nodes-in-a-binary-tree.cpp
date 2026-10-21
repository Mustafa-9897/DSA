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
    // void helper(TreeNode* root,int & maxi){
    //     if(!root) return;
    //     maxi=max(maxi,root->val);
    //     helper(root->left,maxi);
    //     helper(root->right,maxi);
    // }
    // void helper2(TreeNode* root,int& ans){
    //     if(!root) return;
    //     if(root->val>helper(root,))
    // }
    int helper(TreeNode* root,int &ans){
        if(root==NULL) return 0;
        int leftmax=helper(root->left,ans);
        int rightmax=helper(root->right,ans);
        int maxi=max(leftmax,rightmax);
        maxi=max(maxi,root->val);
        if(root->val==maxi) ans++;
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};