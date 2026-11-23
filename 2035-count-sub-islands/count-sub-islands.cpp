class Solution {
public:
    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& vis,int i,int j){
        bool flag=true; // don't 
        vis[i][j]=1;
        int n=grid1.size(),m=grid1[0].size();
        if(grid1[i][j]!=1){
            flag=false;
        }
        vector<int>row={0,-1,0,1};
        vector<int>col={-1,0,1,0};
        for(int k=0;k<4;k++){
            int nr=i+row[k];
            int nc=j+col[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid2[nr][nc]==1){
                if(dfs(grid1,grid2,vis,nr,nc)==false) flag=false;
            }
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int n=grid1.size(),m=grid1[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    if(dfs(grid1,grid2,vis,i,j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};