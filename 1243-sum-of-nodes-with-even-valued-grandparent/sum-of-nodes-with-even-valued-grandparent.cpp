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
    void helper(TreeNode* root,int &sum){
        if(root==NULL) return;
        if(root->val%2==0){
            TreeNode* leftkid=root->left;
            TreeNode* rightkid=root->right;
            if(leftkid){
                if(leftkid->left)
                    sum += leftkid->left->val;
                if(leftkid->right)
                    sum += leftkid->right->val;
            }
            if(rightkid){
                if(rightkid->left)
                    sum += rightkid->left->val;
                if(rightkid->right)
                    sum += rightkid->right->val;
            }
        }
        helper(root->left,sum);
        helper(root->right,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return sum;
    }
};