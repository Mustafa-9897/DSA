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
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
    int findheight(TreeNode* root){
        if(root==NULL) return 0;
        int lh=findheight(root->left);
        int rh=findheight(root->right);
        return 1+max(lh,rh);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        int h=findheight(root);
        while(!qu.empty() && h>1){
            h--;
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode* node=qu.front();
                qu.pop();
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
        // Initially, ans is the first deepest node.
        // The first LCA combines that node with the second deepest node.
        // The next LCA combines their common ancestor with the third deepest node.
        // This continues until every deepest node has been included.
        // at last ans denotes the lca of all the deepest nodes
        TreeNode* ans=qu.front();
        qu.pop();
        while(!qu.empty()){
            TreeNode* node=qu.front();
            qu.pop();
            ans=lca(root,ans,node);
        }
        return ans;
    }
};