class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&image,vector<vector<int>>&vis,int color,int stcolor){
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=image.size();
        int m=image[0].size();
        vis[row][col]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            image[r][c]=color;
            q.pop();
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr*dc!=0) continue;
                    int nr=r+dr;
                    int nc=c+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && image[nr][nc]==stcolor){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int stcolor=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(sr,sc,image,vis,color,stcolor);
        return image;
    }
};