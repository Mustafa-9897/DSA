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
    TreeNode* helper(vector<int>&inorder,int start,int end){
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=helper(inorder,start,mid-1);
        root->right=helper(inorder,mid+1,end);
        return root;
    }
    void findinorder(TreeNode* root,vector<int>&inorder){
        if(root==NULL) return;
        findinorder(root->left,inorder);
        inorder.push_back(root->val);
        findinorder(root->right,inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        findinorder(root,inorder);
        int i=0;
        TreeNode* newroot=helper(inorder,0,inorder.size()-1);
        return newroot;
    }
};