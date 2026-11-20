class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans;
        int ogi,ogj,i,j;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                
                if(!vis[i][j] && land[i][j]==1){
                    //ogi=i;ogj=j;
                    int r=i,c=j;
                    while(c<m && land[r][c]==1){
                        c++;
                    }
                    c--;
                    while(r<n && land[r][c]==1){
                        r++;
                    }
                    r--;
                    for(int x = i; x <= r; x++) {
                        for(int y = j; y <= c; y++) {
                            vis[x][y] = 1;
                        }
                    }
                    ans.push_back({i,j,r,c});
                }
            }
        }
        //if(ans.size()==0) return {};
        return ans;
    }
};