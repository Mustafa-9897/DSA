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
    void dfs(TreeNode* root,unordered_map<int,vector<int>>&adj){
        if(root==NULL) return;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left,adj);
        }

        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right,adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        dfs(root,adj);

        queue<pair<int,int>>q;
        unordered_set<int>vis;

        q.push({start,0});
        vis.insert(start);

        int maxi=0;

        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            maxi=max(maxi,time);

            for(auto it:adj[node]){
                if(vis.count(it)==0){
                    vis.insert(it);
                    q.push({it,time+1});
                }
            }
        }

        return maxi;
    }
};