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
    TreeNode* helper(vector<int>&preorder,int prest,int preend,vector<int>&postorder,int postst,int postend,unordered_map<int,int>&mpp){

        if(prest>preend || postst>postend) return NULL;
        TreeNode* root=new TreeNode(preorder[prest]);

        if(prest==preend) return root;
        int rootidx=mpp[preorder[prest+1]]; // root index of the next subtree
        int numsleft=rootidx-postst+1;

        root->left=helper(preorder,prest+1,prest+numsleft,postorder,postst,rootidx,mpp);
        root->right=helper(preorder,prest+numsleft+1,preend,postorder,rootidx+1,postend,mpp);

        return root; 
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<postorder.size();i++){
            mpp[postorder[i]]=i;
        }
        TreeNode* root=helper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
};