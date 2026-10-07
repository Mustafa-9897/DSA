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
    int findheight(TreeNode* root){
        if(root==NULL) return 0;
        int hl=findheight(root->left);
        int hr=findheight(root->right);
        return 1+max(hl,hr);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=findheight(root->left);
        int rh=findheight(root->right);
        if(abs(lh-rh)>1) return false;
        bool leftcheck=isBalanced(root->left);
        bool rightcheck=isBalanced(root->right);
        if(leftcheck==false || rightcheck==false){
            return false;
        }
        return true;
    }
};