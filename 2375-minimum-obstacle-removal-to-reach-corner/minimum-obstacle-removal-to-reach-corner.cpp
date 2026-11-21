class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<pair<int,int>>>adj(n*m);
        vector<int>row={0,-1,0,1};
        vector<int>col={-1,0,1,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int node=i*m+j;
                for(int del=0;del<4;del++){
                    int nr=row[del]+i;
                    int nc=col[del]+j;
                    int adjnode=nr*m+nc;
                    if(nr<n && nr>=0 && nc<m && nc>=0){
                        adj[node].push_back({adjnode,grid[nr][nc]});
                    }
                }
            }
        }
        int size=n*m;
        vector<int>dist(size,INT_MAX);
        deque<int>q;
        q.push_front(0);
        dist[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop_front();
            if(node==size-1) break;
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
        return dist[size-1];
    }
};