class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>&dist){
        int n=grid.size(),m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int diff=it.first;
            pq.pop();
            if(row==n-1 && col==m-1) return diff;

            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr*dc!=0) continue;
                    int nr=row+dr;
                    int nc=col+dc;

                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        int d=abs(grid[nr][nc]-grid[row][col]);
                        int maxdiff=max(diff,d);
                        
                        if(maxdiff<dist[nr][nc]){
                            dist[nr][nc]=maxdiff;
                            pq.push({maxdiff,{nr,nc}});
                        }
                    }
                }
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        int ans=bfs(heights,dist);
        return ans;
    }
};