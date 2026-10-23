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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        int level=-1;
        bool ans=true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            level++;
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            int n=temp.size();
            for(int i=0;i<n-1;i++){
                if((level%2==0 && temp[i]%2==0) || (level%2==1 && temp[i]%2==1)){
                    ans=false;
                    break;
                }
                if((level%2==0 && temp[i+1]<=temp[i]) || (level%2==1 && temp[i+1]>=temp[i])){
                    ans=false;
                    break;
                }
            }
            if((level%2==0 && temp[n-1]%2==0) || (level%2==1 && temp[n-1]%2==1)){
                ans=false;
                break;
            }         
        }
        return ans;
    }
};