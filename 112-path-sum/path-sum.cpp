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
    void helper(TreeNode* root,vector<int>temp,vector<vector<int>>&ans){
        if(root==NULL) return;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
        }
        else{
            helper(root->left,temp,ans);
            helper(root->right,temp,ans);
        }
        temp.pop_back();
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) false;
        vector<int>temp;
        vector<vector<int>>ans;
        int sum=0;
        helper(root,temp,ans);
        for(int i=0;i<ans.size();i++){
            sum=0;
            for(int j=0;j<ans[i].size();j++){
                sum += ans[i][j];
            }
            if(sum==targetSum) return true;
        }
        return false;
    }
};