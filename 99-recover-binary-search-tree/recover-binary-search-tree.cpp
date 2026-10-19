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
    void helper(TreeNode* root,vector<int>&inorder,int &i){
        if(!root) return ;
        helper(root->left,inorder,i);
        root->val=inorder[i];
        i++;
        helper(root->right,inorder,i);
    }
    void dfs(TreeNode* root,vector<int>&inorder){
        if(!root) return ;
        dfs(root->left,inorder);
        inorder.push_back(root->val);
        dfs(root->right,inorder);
    }
    void recoverTree(TreeNode* root) {
        vector<int>inorder;
        dfs(root,inorder);
        sort(inorder.begin(),inorder.end());
        int i=0;
        helper(root,inorder,i);
        return;
    }
};