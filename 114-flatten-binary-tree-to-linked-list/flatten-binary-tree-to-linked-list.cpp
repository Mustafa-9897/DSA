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
    // void helper(TreeNode* root,vector<TreeNode*>&temp){
    //     if(root==NULL) return;
    //     temp.push_back(root);
    //     helper(root->left,temp);
    //     helper(root->right,temp);
    // }
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        // vector<TreeNode*>ans;
        // if(root==NULL) return ;
        // helper(root,ans);
        // for(int i=0;i<ans.size()-1;i++){
        //     ans[i]->left=NULL;
        //     ans[i]->right=ans[i+1];
        // }
        // ans[ans.size()-1]->left=NULL;
        // ans[ans.size()-1]->right=NULL;
        // return ;
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};