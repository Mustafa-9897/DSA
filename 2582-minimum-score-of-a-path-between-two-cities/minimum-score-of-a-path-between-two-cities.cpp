// class DisjointSet{
// public:
//     vector<int>parent,size,dist;
//     DisjointSet(int n){
//         parent.resize(n+1,0);
//         size.resize(n+1,1);
//         dist.resize(n+1,INT_MAX);
//         for(int i=0;i<=n;i++){
//             parent[i]=i;
//         }
//     }
//     int findUP(int node){
//         if(parent[node]==node) return node;
//         return parent[node]=findUP(parent[node]);
//     }
//     void UnionBySize(int u,int v){
//         int UPu=findUP(u);
//         int UPv=findUP(v);
//         if(UPu==UPv) return;
//         if(size[UPv]>size[UPu]){
//             parent[UPu]=UPv;
//             size[UPv] += size[UPu];
//         }
//         else{
//             parent[UPv]=UPu;
//             size[UPu] += size[UPv];
//         }
//     }
// };
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
    //     DisjointSet ds(n);
    //     for(auto it:roads){
    //         int u=it[0],v=it[1],wt=it[2];
    //         int upu=ds.findUP(u),upv=ds.findUP(v);
    //         int distbeforeu=ds.dist[upu];
    //         int distbeforev=ds.dist[upv];
    //         //if(upu!=upv){
    //             ds.UnionBySize(u,v);
    //             ds.dist[ds.findUP(u)]=min({distbeforeu,distbeforev,wt});
    //         //}
    //     }
    //     return ds.dist[ds.findUP(1)];

        //  optimal
        // go over all the nodes present in the component which contains 1 and find the minimum weight over all the roads

        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads){
            int u=it[0],v=it[1],wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        } 
        vector<int>vis(n+1,0);
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int ans=INT_MAX;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                int adjnode=it.first,wt=it.second;
                ans=min(ans,wt);  // this statement will be at outside of if block if the , the node is visited already but there is an edge that goes to this node again which contains the minimum weight then we have to consider it too
                if(!vis[adjnode]){
                    q.push(adjnode);
                    vis[adjnode]=1;
                }
            }
        }
        return ans;
    }
};