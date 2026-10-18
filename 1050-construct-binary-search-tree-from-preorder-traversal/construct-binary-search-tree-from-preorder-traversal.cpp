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
    TreeNode* helper(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&mpp){

        if(instart>inend || prestart>preend) return NULL;

        TreeNode* root=new TreeNode(preorder[prestart]);
        int inrootidx=mpp[preorder[prestart]];
        int numsleft=inrootidx-instart;

        root->left=helper(preorder,prestart+1,prestart+numsleft,inorder,instart,inrootidx-1,mpp);

        root->right=helper(preorder,prestart+numsleft+1,preend,inorder,inrootidx+1,inend,mpp);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* newroot=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return newroot;
    }
};