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
    // int floor(TreeNode* root,int key){
    //     int floor=-1;
    //     while(root){
    //         if(root->val==key){
    //             floor=key;
    //             break;
    //         }
    //         else if(root->val<key){
    //             floor=root->val;
    //             root=root->right;
    //         }
    //         else root=root->left;
    //     }
    //     return floor;
    // }
    // int ceil(TreeNode* root,int key){
    //     int ceil=-1;
    //     while(root){
    //         if(root->val==key){
    //             ceil=key;
    //             break;
    //         }
    //         else if(root->val>key){
    //             ceil=root->val;
    //             root=root->left;
    //         }
    //         else root=root->right;
    //     }
    //     return ceil;
    // }
    void findinorder(TreeNode* root,vector<int>&inorder){
        if(root==NULL) return;
        findinorder(root->left,inorder);
        inorder.push_back(root->val);
        findinorder(root->right,inorder);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n=queries.size();
        vector<int>inorder;
        findinorder(root,inorder);
        vector<vector<int>>ans(n,vector<int>(2));
        for(int i=0;i<n;i++){
            int key=queries[i];
            // Floor: largest element <= key
            auto it1 = upper_bound(inorder.begin(), inorder.end(), key);

            int floorval = -1;
            if (it1 != inorder.begin()) {
                floorval = *(it1 - 1);
            }

            // Ceil: smallest element >= key
            auto it2 = lower_bound(inorder.begin(), inorder.end(), key);

            int ceilval = -1;
            if (it2 != inorder.end()) {
                ceilval = *it2;
            }
            ans[i][0]=floorval;
            ans[i][1]=ceilval;
        }
        return ans;
    }
};