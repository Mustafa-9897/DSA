class Solution {
public:
    bool bfs(int start,vector<vector<int>>&graph,vector<int>&color){
        color[start]=0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                // if the adjacent node is not yet visited then color it the opposite color of its parent node
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                // if the adjacent node is already having the same color 
                // someone colored it on other path 
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color)==false) return false;
            }
        }
        return true;
    }
};