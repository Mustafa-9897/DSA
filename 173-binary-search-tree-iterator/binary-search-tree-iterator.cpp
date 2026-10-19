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
class BSTIterator {
public:
    vector<int>inorder;
    int i;

    void findinorder(TreeNode* root){
        if(root==NULL) return ;
        findinorder(root->left);
        inorder.push_back(root->val);
        findinorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        i=0;
        findinorder(root);
    }
    
    int next() {
        int value=inorder[i];
        i++;
        return value;
    }
    
    bool hasNext() {
        return i<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */