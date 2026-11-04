class Solution {
public:
    void toposortvector(vector<int>&topo,vector<vector<int>>&edges,int k){
        vector<int>indegree(k+1,0);
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges[i].size();j++){
                indegree[edges[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:edges[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    }

    void toposort(unordered_map<int,int>&topo,vector<vector<int>>&edges,int k){
        vector<int>indegree(k+1,0);
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges[i].size();j++){
                indegree[edges[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo[node]=cnt;
            cnt++;
            for(auto it:edges[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<vector<int>>adjrow(k+1);
        for(auto it:rowConditions){
            int u=it[0];
            int v=it[1];
            adjrow[u].push_back(v);
        }

        vector<vector<int>>adjcol(k+1);
        for(auto it:colConditions){
            int u=it[0];
            int v=it[1];
            adjcol[u].push_back(v);
        }
        vector<int>row;
        toposortvector(row,adjrow,k);
        unordered_map<int,int>col;
        toposort(col,adjcol,k);

        vector<vector<int>>ans(k,vector<int>(k,0));

        // if the row or col topo sort is invalid means their exists a cycle so we will return an empty matrix as said
        if(row.size()!=k || col.size()!=k) return {};

        for(int i=0;i<row.size();i++){
            int c=col[row[i]];
            ans[i][c]=row[i];
        }
        return ans;
    }
};