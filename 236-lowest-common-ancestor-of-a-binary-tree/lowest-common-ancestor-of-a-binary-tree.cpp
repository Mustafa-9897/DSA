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
    bool helper(TreeNode* root,vector<TreeNode*>&temp,int x){
        if(root==NULL) return false;
        temp.push_back(root);
        if(root->val==x) return true;
        if(helper(root->left,temp,x) || helper(root->right,temp,x))
            return true;
        temp.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*>t1;
        // vector<TreeNode*>t2;
        // int val1=p->val;
        // int val2=q->val;
        // helper(root,t1,val1);
        // helper(root,t2,val2);
        // int i=0,j=0;
        // TreeNode* ans=root; 
        // while(i<t1.size() && j<t2.size()){
        //     if(t1[i]==t2[j]){
        //         ans=t1[i];
        //     }
        //     else{
        //         break;
        //     }
        //     i++;
        //     j++;
        // }
        // return ans;

        if(root==NULL) return NULL;
        if(root==p) return p;
        else if(root==q) return q;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        // if(left==NULL && right!=NULL) return right;
        // else if(right==NULL && left!=NULL) return left;
        // else if(left==NULL && right==NULL) return NULL;
        // else return root;

        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
};