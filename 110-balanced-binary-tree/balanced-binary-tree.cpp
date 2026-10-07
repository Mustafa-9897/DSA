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
    // int findheight(TreeNode* root){
    //     if(root==NULL) return 0;
    //     int hl=findheight(root->left);
    //     int hr=findheight(root->right);
    //     return 1+max(hl,hr);
    // }

    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int lh=helper(root->left);
        int rh=helper(root->right);
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        //  RECURSIVE
        // if(root==NULL) return true;
        // int lh=findheight(root->left);
        // int rh=findheight(root->right);
        // if(abs(lh-rh)>1) return false;
        // bool leftcheck=isBalanced(root->left);
        // bool rightcheck=isBalanced(root->right);
        // if(!leftcheck || !rightcheck){  // same as leftcheck==false || rightcheck==false
        //     return false;
        // }
        // return true;

        // OPTIMAL
        int height=helper(root);
        if(height==-1) return false;
        return true;
    }
};