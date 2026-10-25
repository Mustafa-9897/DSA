class Solution {
public:
    void helper(vector<vector<int>>&vis,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr*dc!=0) continue;
                    int nr=r+dr;
                    int nc=c+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        helper(vis,grid);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};