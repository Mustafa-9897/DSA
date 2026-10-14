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
    // void helper(TreeNode* node,vector<int>&ans){
    //     if(node==NULL){
    //         return ;
    //     }
    //     ans.push_back(node->val);
    //     helper(node->left,ans);
    //     helper(node->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // TreeNode* node=root;
        // helper(node,ans);
        // return ans;

        // ITERATIVE WITHOUT USING EXTRA SPACE , CALLED MORRIS TARVERSAL
        TreeNode* curr=root;
        vector<int>preorder;
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};