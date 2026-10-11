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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int minidx=q.front().second;
            int startidx,endidx;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                long long curridx=q.front().second-minidx;
                q.pop();
                if(i==0) startidx=curridx;
                if(i==size-1) endidx=curridx;
                if(node->left) q.push({node->left,curridx*2+1});
                if(node->right) q.push({node->right,curridx*2+2});
            }
            ans=max(ans,endidx-startidx+1);
        }
        return ans;
    }
};