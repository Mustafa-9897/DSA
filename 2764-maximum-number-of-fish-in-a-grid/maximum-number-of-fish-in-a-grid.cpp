class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int &sum){
        vis[row][col]=1;
        sum += grid[row][col];
        int n=grid.size(),m=grid[0].size();
        vector<int>r={0,-1,0,1};
        vector<int>c={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=row+r[i];
            int nc=col+c[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]!=0){
                dfs(nr,nc,vis,grid,sum);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         maxi=max(maxi,grid[i][j]);
        //     }
        // }
        //if(maxi==0) return 0;
        int ans=0,sum;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>>vis(n,vector<int>(m,0));
                sum=0;
                if(grid[i][j]!=0){
                    dfs(i,j,vis,grid,sum);
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};