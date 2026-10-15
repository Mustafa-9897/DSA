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
class FindElements {
public:
    unordered_map<int,int>mpp;

    void helper(TreeNode* root){
        if(root==NULL) return;
        int x=root->val;
        mpp[x]=1;
        if(root->left){
            root->left->val=2*x+1;
            mpp[2*x+1]=1;
        }
        if(root->right){
            root->right->val=2*x+2;
            mpp[2*x+2]=1;
        }
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
    }

    FindElements(TreeNode* root) {  // its a constructor , it is not a function you cannot use 
        if(root==NULL) return;      // it to do recursion over the tree
        root->val=0;
        helper(root);
    }
    
    bool find(int target) {
        if(mpp.find(target)!=mpp.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */