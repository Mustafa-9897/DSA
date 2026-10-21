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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        map<int,int>mpp;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(mpp.find(level)==mpp.end()){
                    mpp[level]=node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        int ans=0;
        level=0;
        for(auto it:mpp){
            if(it.first>level){
                ans=it.second;
                level=it.first;
            }
        }
        return ans;
    }
};