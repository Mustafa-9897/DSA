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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int maxi=0;
        vector<int>row={0,-1,0,1};
        vector<int>col={-1,0,1,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int node=i*n+j;
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nr=row[k]+i; int nc=col[k]+j;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int adjnode=nr*n+nc;
                            ds.UnionBySize(node,adjnode);
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1) continue;
                int cnt=1;
                int node=i*n+j;
                unordered_set<int>st;

                for(int k=0;k<4;k++){
                    int nr=i+row[k];
                    int nc=j+col[k];

                    if(nr<n && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==1){
                        int adjnode=nr*n+nc;
                        int UP=ds.findUP(adjnode);
                        if(st.count(UP)==0){
                            cnt += ds.size[UP];
                            st.insert(UP);
                        }
                    }
                }
                maxi=max(maxi,cnt);
            }
        }
        // all ones int he isalnd edge case
        if(maxi==0) return n*n;

        //if there is a single island in the grid that is larger than we could make by connecting any other islands hten we'll have to consider it
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findUP(i)]);
        }
        return maxi;
    }
};