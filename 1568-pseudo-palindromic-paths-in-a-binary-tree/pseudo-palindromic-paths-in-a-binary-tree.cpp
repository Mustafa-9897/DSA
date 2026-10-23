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
    void helper(TreeNode* root,unordered_map<int,int>&mpp,int &ans,int cnt){
        if(!root) return;
        mpp[root->val]++;
        cnt++;
        if(!root->left && !root->right){
            int count=0;
            //if((cnt%2==0 && mpp.size()==cnt/2) || (cnt%2==1 && mpp.size()==cnt/2+1)) ans++;
            for(auto it:mpp){
                if(it.second%2==1) count++;
                if(count>1){
                    break;
                }
            }
            if(cnt%2==0){
                if(count==0) ans++;
            }
            else{
                if(count==1) ans++;
            }
        }
        else{
            helper(root->left,mpp,ans,cnt);
            helper(root->right,mpp,ans,cnt);
        }
        mpp[root->val]--;
        if(mpp[root->val]==0) mpp.erase(root->val);
        cnt--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mpp;
        int ans=0;
        helper(root,mpp,ans,0);
        return ans;
    }
};