class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>rowmax(n);
        vector<int>colmax(n);
        for(int i=0;i<n;i++){
            int maxi1=0;
            int maxi2=0;
            for(int j=0;j<n;j++){
                maxi1=max(maxi1,grid[i][j]);
                maxi2=max(maxi2,grid[j][i]);
            }
            rowmax[i]=maxi1;
            colmax[i]=maxi2;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cnt += min(rowmax[i],colmax[j])-grid[i][j];
            }
        }
        return cnt;
    }
};