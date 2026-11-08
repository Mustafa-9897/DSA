class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        dfs(k,vis,adj);
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(i);
        }
        for(int i=0;i<invocations.size();i++){
            auto it=invocations[i];
            if(vis[it[0]]==0 && vis[it[1]]==1) return temp;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0) ans.push_back(i);
        }
        return ans;
    }
};