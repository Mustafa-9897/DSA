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
    void helper(TreeNode* root,vector<int>&ans,int level){
        if(root==NULL) return;
        if(level==ans.size()) ans.push_back(root->val);
        helper(root->right,ans,level+1);
        helper(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // ITERATIVE USING QUEUE AND MAP
        // vector<int>ans;
        // if(root==NULL) return ans;
        // queue<pair<TreeNode*,int>>q;
        // map<int,int>mpp;
        // q.push({root,0});
        // while(!q.empty()){
        //     auto it=q.front();
        //     q.pop();
        //     TreeNode* node=it.first;
        //     int level=it.second;
        //     mpp[level]=node->val;
        //     if(node->left) q.push({node->left,level+1});
        //     if(node->right) q.push({node->right,level+1});
        // }
        // for(auto it:mpp){
        //     ans.push_back(it.second);
        // }
        // return ans;

        // OPTIMAL
        vector<int>ans;
        if(root==NULL) return ans;
        helper(root,ans,0);
        return ans;
    }
};