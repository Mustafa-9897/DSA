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
    // bool isSymmetricHelper(TreeNode* left,TreeNode* right){
    //     if(left==NULL || right==NULL){
    //         return (left==right);
    //     }
    //     if(left->val != right->val) return false;
        
    //     // check if the outer side and inner side of the left and right subtrees are also equal or not 
    //     return (isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left));
    // }

    bool isSymmetric(TreeNode* root) {
        // RECURSIVE
        // if(root==NULL) return true;
        // return isSymmetricHelper(root->left,root->right);

        //  ITERATIVE USING QUEUE      
        if (root == nullptr) {
            return true;
        }
        queue<pair<TreeNode*, TreeNode*>>q;
        q.push({root->left, root->right});
 
        while (!q.empty()) {

            auto [leftnode, rightnode] = q.front(); // distributes the two values of the pair stored in the queue to two variables leftnode and rightnode
            q.pop();
 
            if (leftnode == nullptr && rightnode == nullptr) {
                continue;
            }
            if (leftnode == nullptr || rightnode == nullptr) {
                return false; // since both null vala case hamne upar hi handle kiya already
            }
            if (leftnode->val != rightnode->val) {
                return false;
            }
            // * Store children in crossed pairs because
            // * opposite directions must mirror each other.
            q.push({leftnode->left,rightnode->right});
            q.push({leftnode->right,rightnode->left});
        }
        return true;

        // U CAN ALSO DO THE SAME ITERATIVE USING STACK
    }
};