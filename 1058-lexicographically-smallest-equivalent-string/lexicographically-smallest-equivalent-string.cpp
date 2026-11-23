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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            int node1=s1[i]-'a',node2=s2[i]-'a';
            if(ds.findUP(node1)!=ds.findUP(node2)){
                ds.UnionBySize(node1,node2);
            }
        }
        unordered_map<char,vector<char>>mpp;;
        for(int i=0;i<26;i++){
            int node=i;
            int parent=ds.findUP(node);
            mpp[parent].push_back(node);
        }
        for(auto &it:mpp){
            vector<char>curr=it.second;
            sort(curr.begin(),curr.end());
            it.second=curr;
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            int parent=ds.findUP(baseStr[i]-'a');
            ans += mpp[parent][0]+'a';
        }
        return ans;
    }
};