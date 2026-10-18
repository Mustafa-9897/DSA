/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL || root==p || root==q) return root;
        // TreeNode* left=lowestCommonAncestor(root->left,p,q);
        // TreeNode* right=lowestCommonAncestor(root->right,p,q);
        // if(left==NULL) return right;
        // else if(right==NULL) return left;
        // return root;

        //   OPTIMAL , you can also do this using while loop
        // if(root==NULL) return NULL;
        // if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        // if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        // return root;

        while(root){
            if(root==NULL || root==p || root==q) return root;
            if(root->val<p->val && root->val<q->val){
                root=root->right;
            }
            else if(root->val>p->val && root->val>q->val){
                root=root->left;
            }
            else return root;
        }
        return NULL;
    }
};