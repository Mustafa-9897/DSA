class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>&dist){
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int d=it.first;
            pq.pop();
            if(row==n-1 && col==n-1) break;
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int nr=row+dr;
                    int nc=col+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && d+1<dist[nr][nc] && grid[nr][nc]==0){
                        dist[nr][nc]=d+1;
                        pq.push({d+1,{nr,nc}});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // U CAN ALSO USE ONLY QUEUE IN THIS QUESTION INSTEAD OF PRIORITY QUEUE , BECAUSE ALL THE DISTNCES ARE OF WEIGHT 1 SO EVERY COMBINATION IS SAME FOR P_Q IT CANNOT DISTINGUISH BETWEEN IT. STORE ONLY THE {ROW,COL} IN THE Q .
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        int ans=bfs(grid,dist);
        return ans;
    }
};