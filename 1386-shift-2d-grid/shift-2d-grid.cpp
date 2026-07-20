class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        k = k % total;
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=i*n+j; // assume the 2D grid as 1D grid, so idx= index of that el. in 1D grid
                int newidx=(idx+k)%total; // after shifting what will be the new index in the 2D grid
                int row=newidx/n;  // row and column of the newidx in 2D grid
                int col=newidx%n;
                ans[row][col]=grid[i][j];
            }
        }
        return ans;
    }
};