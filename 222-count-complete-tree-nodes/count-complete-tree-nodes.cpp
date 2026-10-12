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
    // void helper(TreeNode* root,int & ans){
    //     if(root==NULL) return;
    //     ans++;
    //     helper(root->left,ans);    // WORKS IN THETA(N) , SO DOESN'T PASS THE RESTRICTIONS
    //     helper(root->right,ans);
    // }
    int findleftheight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }
    int findrightheight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        // if(root==NULL) return 0;
        // int ans=0;
        // helper(root,an s);
        // return ans;

        if(root==NULL) return 0;
        int lh=findleftheight(root);
        int rh=findrightheight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};