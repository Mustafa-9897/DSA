class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>edges;
        
        vector<vector<pair<int,int>>>adj(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int node=i*m+j;
                for(int dr=-1;dr<=1;dr++){
                    for(int dc=-1;dc<=1;dc++){
                        if(dr*dc!=0) continue;
                        int nr=dr+i;
                        int nc=dc+j;
                        int adjnode=nr*m+nc;
                        if(nr<n && nr>=0 && nc<m && nc>=0){
                            adj[node].push_back({adjnode,grid[nr][nc]});
                        }
                    }
                }
            }
        }
        
        vector<int>dist(n*m,INT_MAX);
        deque<int>q;
        q.push_front(0);
        dist[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop_front();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dist[adjnode]>dist[node]+wt){
                    dist[adjnode]=dist[node]+wt;
                    if(wt==0){
                        q.push_front(adjnode);
                    }
                    else if(wt==1){
                        q.push_back(adjnode);
                    }
                }
            }
        }
        return dist[n*m-1];
    }
};