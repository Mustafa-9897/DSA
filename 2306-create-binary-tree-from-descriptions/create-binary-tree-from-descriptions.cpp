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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_map<int,TreeNode*>childrens;
        TreeNode* parent;
        TreeNode* child;
        for(int i=0;i<descriptions.size();i++){
            if(mpp.find(descriptions[i][0])==mpp.end())
                mpp[descriptions[i][0]]=new TreeNode(descriptions[i][0]);
            parent=mpp[descriptions[i][0]];
            if(mpp.find(descriptions[i][1])==mpp.end()){
                mpp[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
            }
            if(childrens.find(descriptions[i][1])==mpp.end()){
                childrens[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
            }
            child=mpp[descriptions[i][1]];
            if(descriptions[i][2]==1){
                parent->left=child;
            }
            else{
                parent->right=child;
            }
        }
        for(auto it:mpp){
            if(childrens.find(it.first)==mpp.end()){
                return it.second;
            }
        }
        return NULL;
    }
};