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
        TreeNode* helper(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend,map<int,int>&mpp){

        if(poststart<postend || instart>inend) return NULL;
        TreeNode* root=new TreeNode(postorder[poststart]);

        int inrootidx=mpp[root->val];
        int numsright=inend-inrootidx;

        root->right=helper(postorder,poststart-1,poststart-numsright,inorder,inrootidx+1,inend,mpp);

        root->left=helper(postorder,poststart-numsright-1,postend,inorder,instart,inrootidx-1,mpp);

        return root;
        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=helper(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};