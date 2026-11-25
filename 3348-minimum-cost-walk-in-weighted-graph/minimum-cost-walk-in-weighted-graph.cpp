class DisjointSet{
public:
    vector<int>parent,size,cost;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        cost.resize(n+1,INT_MAX);
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            int andBeforeU=ds.cost[ds.findUP(u)];
            int andBeforeV=ds.cost[ds.findUP(v)];
            ds.UnionBySize(u,v);
            if(ds.cost[ds.findUP(u)]!=INT_MAX && ds.cost[ds.findUP(v)]!=INT_MAX) {
                ds.cost[ds.findUP(u)] = (andBeforeU)&(andBeforeV)&(wt);
            }
            else{
                ds.cost[ds.findUP(u)] &= wt;
            }
        }
        vector<int>ans;
        for(auto it:query){
            int u=it[0],v=it[1];
            if(ds.findUP(u)!=ds.findUP(v)){
                ans.push_back(-1);
            }
            else{
                ans.push_back(ds.cost[ds.findUP(u)]);
            }
        }
        return ans;
    }
};