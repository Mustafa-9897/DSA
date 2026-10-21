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
    void helper(TreeNode* root,vector<int>&temp,vector<vector<int>>&ans){
        if(root==NULL) return;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        else{
            helper(root->left,temp,ans);
            helper(root->right,temp,ans);
        }
        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root,temp,ans);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            int num=0;
            int j=0;
            while(j<ans[i].size()){
                num = num*10+ans[i][j];
                j++;
            }
            sum += num;
        }
        return sum;
    }
};