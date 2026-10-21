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
    static bool comparator(vector<int>&a,vector<int>&b){
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0 && j>=0){
            if(a[i]!=b[j])
                return a[i]<b[j];
            i--;
            j--;
        }
        return a.size()<b.size();
    }
    void helper(TreeNode* root,vector<int>&temp,vector<vector<int>>&ans){
        if(root==NULL) return;
        temp.push_back(root->val);
        if(!root->left && !root->right) ans.push_back(temp);
        else{
            helper(root->left,temp,ans);
            helper(root->right,temp,ans);
        }
        temp.pop_back();
    }
    string numbertostring(vector<int>&nums){
        string s="";
        for(int i=nums.size()-1;i>=0;i--){
            s += char(nums[i]+97);
        }
        int i=0,j=0;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<int>temp;
        vector<vector<int>>ans;
        helper(root,temp,ans);
        sort(ans.begin(),ans.end(),comparator);
        string s=numbertostring(ans[0]);
        return s;
    }
};