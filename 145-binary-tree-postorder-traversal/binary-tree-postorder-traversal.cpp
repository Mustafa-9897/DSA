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
    // void helper(TreeNode *node,vector<int>&ans){
    //     if(node==NULL){
    //         return ;
    //     }
    //     helper(node->left,ans);
    //     helper(node->right,ans);
    //     ans.push_back(node->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // TreeNode *node=root;
        // helper(root,ans);
        // return ans;
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        if(root==NULL) return ans;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=NULL){
                st1.push(root->left);
            }
            if(root->right!=NULL){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};