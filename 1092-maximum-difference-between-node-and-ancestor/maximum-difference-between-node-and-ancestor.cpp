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
    int ans=0;
    void helper(TreeNode* root,int maxi,int mini){
        if(root==NULL) return;
        maxi=max(root->val,maxi);  // maxi and mini are passed by values so while going from 
        mini=min(root->val,mini);  // left subtree to right subtree eg. 1 3 6 (l root r)
        ans=max(ans,abs(maxi-mini));   // for the left subtree mini=1,maxi=8 now while backtracking
        helper(root->left,maxi,mini); // when we come to 3 the mini will become 3 , the mini of
        helper(root->right,maxi,mini); // the subtree that was before going to left
    }
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
};