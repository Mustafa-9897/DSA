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
    TreeNode* reverseOddLevels(TreeNode* root) {

        if(root->left==NULL && root->right==NULL) return root;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;

        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*>level;
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(cnt%2==1){
                int l=0;
                int r=size-1;
                while(l<r){
                    swap(level[l]->val,level[r]->val);
                    l++;
                    r--;
                }
            }
            cnt++;
        }
        return root;
    }
};