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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(root==NULL) return node;
        TreeNode* newroot=root;
        TreeNode* parent=root;
        int left,right;
        while(newroot){
            parent=newroot;
            left=0;
            right=0;
            if(newroot->val<val){
                newroot=newroot->right;
                right=1;
            }
            else{
                newroot=newroot->left;
                left=1;
            }
        }
        if(left==1)
            parent->left=node;
        else
            parent->right=node;
        return root;
    }
};