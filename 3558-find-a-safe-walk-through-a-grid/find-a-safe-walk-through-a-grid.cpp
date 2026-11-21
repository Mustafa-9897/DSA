class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({health,{0,0}});

        vector<vector<int>>h(n,vector<int>(m,0));
        h[0][0]=health;
        vector<int>r={0,-1,0,1};
        vector<int>c={-1,0,1,0};
        //int cnt=health;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int row=it.second.first;
            int col=it.second.second;
            int val=it.first;
            // if(val==1) cnt--;
            if(row==n-1 && col==m-1) break;
            for(int i=0;i<4;i++){
                int nr=row+r[i];
                int nc=col+c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(grid[row][col]==1){
                        if(h[nr][nc]<h[row][col]-1){
                            h[nr][nc]=h[row][col]-1;
                            pq.push({h[nr][nc],{nr,nc}});
                        }
                    }
                    else{
                        if(h[nr][nc]<h[row][col]){
                            h[nr][nc]=h[row][col];
                            pq.push({h[nr][nc],{nr,nc}});
                        }
                    }
                }
            }
        }
        if(grid[n-1][m-1]==1) h[n-1][m-1]--;
        if(h[n-1][m-1]>=1) return true;
        return false;
    }
};