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
    int findsum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+findsum(root->left)+findsum(root->right);
    }
    int findcnt(TreeNode* root){
        if(root==NULL) return 0;
        return 1+findcnt(root->left)+findcnt(root->right);
    }
    void helper(TreeNode* root,int& ans){
        if(root==NULL) return ;
        int sum=findsum(root);
        int count=findcnt(root);
        if(root->val==sum/count) ans++;
        helper(root->left,ans);
        helper(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};