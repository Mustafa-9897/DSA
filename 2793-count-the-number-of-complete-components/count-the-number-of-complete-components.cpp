class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&comp){
        vis[node]=1;
        comp.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt=0;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>comp;
                dfs(i,vis,adj,comp);

                int totalvertex=comp.size();
                int iscomplete=1;

                for(auto node:comp){
                    if(adj[node].size()!=totalvertex-1){
                        iscomplete=0;
                        break;
                    }
                }
                if(iscomplete) cnt++;
            }
        }
        return cnt;
    }
};