// disjoint set data structure
class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
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
        if(size[UPu]>size[UPv]){
            parent[UPv]=UPu;
            size[UPu]++;
        }
        else{
            parent[UPu]=UPv;
            size[UPv]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges=0;
        // count the number of extra edges
        for(auto it:connections){
            int u=it[0],v=it[1];
            if(ds.findUP(u)==ds.findUP(v)) extraEdges++;
            else ds.UnionBySize(u,v);
        }
        int nc=0;
        // count the number of components
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) nc++;
        }
        if(nc-1<=extraEdges) return nc-1;
        return -1;
    }
};