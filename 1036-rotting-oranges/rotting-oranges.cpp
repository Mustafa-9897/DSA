class Solution {
public:
    void helper(vector<vector<int>>& vis,vector<vector<int>>& grid,int& minutes){
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size(),m=grid[0].size();
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    q.push({{i,j},time});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                int row=q.front().first.first;
                int col=q.front().first.second;
                q.pop();
                for(int dr=-1;dr<=1;dr++){
                    for(int dc=-1;dc<=1;dc++){
                        if(dr*dc!=0) continue;
                        int nr=row+dr;
                        int nc=col+dc;
                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                            q.push({{nr,nc},time});
                            vis[nr][nc]=1;
                            minutes=max(minutes,time);
                        }
                    }
                }
            }
        }
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int minutes=0;
        helper(vis,grid,minutes);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return minutes;
    }
};