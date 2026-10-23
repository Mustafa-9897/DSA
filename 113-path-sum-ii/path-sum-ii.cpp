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
    void helper(TreeNode* root,vector<int>&temp,vector<vector<int>>&ans,int targetSum,int sum){
        if(!root) return ;
        temp.push_back(root->val);
        sum += root->val;
        if(!root->left && !root->right && sum==targetSum) ans.push_back(temp);
        else{
            helper(root->left,temp,ans,targetSum,sum);
            helper(root->right,temp,ans,targetSum,sum);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        //vector<vector<int>>nums;
        vector<int>temp;
        helper(root,temp,ans,targetSum,0);
        // for(int i=0;i<ans.size();i++){
        //     int sum=0;
        //     for(int j=0;j<ans[i].size();j++){
        //         sum += ans[i][j];
        //     }
        //     if(sum==targetSum) nums.push_back(ans[i]);
        // }
        return ans;
    }
};