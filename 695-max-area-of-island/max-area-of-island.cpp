class Solution {
public:
    void dfs(int row,int col,int &cnt,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<int>&temp){
        int n=grid.size(),m=grid[0].size();
        vis[row][col]=1;
        cnt++;
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(dr*dc!=0) continue;
                int nr=row+dr;
                int nc=col+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    dfs(nr,nc,cnt,grid,vis,temp);
                }
            }
        }
        temp.push_back(cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,cnt,grid,vis,temp);
                }
            }
        }
        int ans=0;
        for(int i=0;i<temp.size();i++){
            ans=max(ans,temp[i]);
        }
        return ans;
    }
};