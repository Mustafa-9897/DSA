class Solution {
public:
    // bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
    //     vis[node]=1;
    //     pathvis[node]=1;
    //     check[node]=0;
    //     for(auto adjnode:graph[node]){
    //         if(!vis[adjnode]){
    //             if(dfs(adjnode,graph,vis,pathvis,check)==true){
    //                 check[node]=0;
    //                 return true;
    //             }
    //         }
    //         else if(pathvis[adjnode]){
    //             check[node]=0;
    //             return true;
    //         }
    //     }
    //     check[node]=1;
    //     pathvis[node]--;
    //     return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // int n=graph.size();
        // vector<int>vis(n,0);
        // vector<int>pathvis(n,0);
        // vector<int>check(n,0);
        // vector<int>safenodes;
        // for(int i=0;i<n;i++){
        //     if(!vis[i])
        //         dfs(i,graph,vis,pathvis,check);
        // }
        // for(int i=0;i<n;i++){
        //     if(check[i]==1)
        //         safenodes.push_back(i);
        // }
        // return safenodes;

        int n=graph.size();
        vector<int>safenodes;
        vector<int>indegree(n,0);
        queue<int>q;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};