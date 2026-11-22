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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0,maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        // the ds will consists of nodes i.e rows and cols
        DisjointSet ds(maxrow+maxcol+1);

        // the mpp will consists of rows and cols as their node's val , even if there are multiple stones within a ro w still that row will be only available ones in the mpp 
        unordered_map<int,int>mpp;

        for(auto it:stones){
            int stonerow=it[0];
            int stonecol=it[1]+maxrow+1;
            mpp[stonerow]=1;
            mpp[stonecol]=1;
            // if there is a stone at (r,c) then we will unite the row r and column c as a single component
            ds.UnionBySize(stonerow,stonecol);
        }
        int cnt=0;
        for(auto it:mpp){
            // when you go over nodes present in the map , if you find an Ultimate Parent means that is a component , so add it to the no. of components 
            if(ds.findUP(it.first)==it.first){
                cnt++;
            }
        }
        //return (no. of stones)-(no. of components)
        return n-cnt;
    }
};