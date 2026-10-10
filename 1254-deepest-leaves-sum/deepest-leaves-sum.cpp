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
    void helper2(TreeNode* root,int &ans,int h,int level){
        if(level==h) ans += root->val;
        if(root->left)
            helper2(root->left,ans,h,level+1);
        if(root->right)
            helper2(root->right,ans,h,level+1);
    }
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int lefth=helper(root->left);
        int righth=helper(root->right);
        return 1+max(lefth,righth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=helper(root);
        int ans=0;

        //helper(root,ans,h,0) this is wrong
        
        helper2(root,ans,h,1);  // since in helper , if there is only node then the heightis measured as 1 since 1+max(0,0)=1 so while putting level in helper2 start from 1 not 0
        return ans;
    }
};