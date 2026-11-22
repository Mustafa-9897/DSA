class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUP(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUP(parent[node]);
    }
    void UnionBySize(int u,int v){
        int UPu=findUP(u);
        int UPv=findUP(v);
        if(UPu==UPv) return;
        if(size[UPv]>size[UPu]){
            parent[UPu]=UPv;
            size[UPv] += size[UPu];
        }
        else{
            parent[UPv]=UPu;
            size[UPu] += size[UPv];
        }
    }
};
class Solution {
public:
    // void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    //     vis[node]=1;
    //     for(auto it:adj[node]){
    //         if(!vis[it]){
    //             dfs(it,adj,vis);
    //         }
    //     }
    // }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // int n=isConnected.size();
        // vector<vector<int>>adj(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1 && i!=j){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        // vector<int>vis(n+1,0);
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(vis[i]==0){
        //         cnt++;
        //         dfs(i,adj,vis);
        //     }
        // }
        // return cnt;

        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.UnionBySize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUP(i)==i){
                cnt++;
            }
        }
        return cnt;
    }
};