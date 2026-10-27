class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col){
        vis[row][col]=1;
        int n=board.size(),m=board[0].size();
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(dr*dc!=0) continue;
                int nr=row+dr;
                int nc=col+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='X'){
                    dfs(board,vis,nr,nc);
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    cnt++;
                    dfs(board,vis,i,j);
                }
            }
        }
        return cnt;
    }
};