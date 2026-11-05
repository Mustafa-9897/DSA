class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>&dist){
        int n=grid.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            int row=it.first;
            int col=it.second;
            int d=dist[row][col];
            pq.pop();
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int nr=row+dr;
                    int nc=col+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && d+1<dist[nr][nc] && grid[nr][nc]==0){
                        dist[nr][nc]=d+1;
                        pq.push({nr,nc});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        int ans=bfs(grid,dist);
        return ans;
    }
};