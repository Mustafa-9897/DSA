class Solution {
public:
    void helper(vector<vector<int>>&mat , vector<vector<int>>&vis){
        queue<pair<pair<int,int>,int>>q;
        int n=mat.size(),m=mat[0].size();
        int dist=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},dist});
                    vis[i][j]=dist;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr*dc!=0) continue;
                    int nr=row+dr;
                    int nc=col+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]==1){
                        q.push({{nr,nc},dist+1});
                        vis[nr][nc]=dist+1;
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        helper(mat,vis);
        return vis;
    }
};