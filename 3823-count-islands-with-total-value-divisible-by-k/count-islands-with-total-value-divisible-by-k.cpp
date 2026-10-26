class Solution {
public:
    void helper(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,int &ans,int k){
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        q.push({row,col});
        vis[row][col]=1;
        long long sum=0;
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            sum += grid[row][col];
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr*dc!=0) continue;
                    int nr=row+dr;
                    int nc=col+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]!=0){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        if(sum%k==0) ans++;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    helper(i,j,grid,vis,ans,k);
                }
            }
        }
        return ans;
    }
};