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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        //we only need to compare the adjacents , since consider idx 0 and 1 if nums[0]-nums[1]
        //is <= maxDiff then we connect 0&1 the you compare 1 and 2 if nums[1]-nums[2] <= maxDiff then 1 and 2 get connected but 0 is also already in that component so 2 gets connected with 1 also so just compare the adjacents
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                ds.UnionBySize(i,i-1);
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0],v=queries[i][1];
            if(ds.findUP(u)==ds.findUP(v)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};