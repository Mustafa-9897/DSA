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
    // void helper(TreeNode* root,vector<int>&inorder,int &i){
    //     if(!root) return ;
    //     helper(root->left,inorder,i);
    //     root->val=inorder[i];
    //     i++;
    //     helper(root->right,inorder,i);
    // }
    // void dfs(TreeNode* root,vector<int>&inorder){
    //     if(!root) return ;
    //     dfs(root->left,inorder);
    //     inorder.push_back(root->val);
    //     dfs(root->right,inorder);
    // }
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root==NULL) return;

        inorder(root->left);

        // violation
        if(prev!=NULL && root->val<prev->val){
            // means first violation
            if(first==NULL){
                first=prev;
                middle=root;
            }
            // means second violation
            else{
                last=root;
            }
        }
        // move to the next node by updating the prev node
        prev=root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        // vector<int>inorder;
        // dfs(root,inorder);
        // sort(inorder.begin(),inorder.end());
        // int i=0;
        // helper(root,inorder,i);
        // return;

        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);  // else if is important
    }
};