class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //     WRONG , GREEDILY CHOOSING THE SMALLEST NEIGHBOR
        // int n=grid.size();
        // vector<vector<int>>vis(n,vector<int>(n,0));
        // queue<pair<int,int>>q;
        // q.push({0,0});
        // vis[0][0]=1;
        // int maxi=0;
        // vector<int>rowvec={0,-1,0,1};
        // vector<int>colvec={-1,0,1,0};
        // while(!q.empty()){
        //     int row=q.front().first;
        //     int col=q.front().second;
        //     q.pop();
        //     if(row==n-1 && col==n-1) break;
        //     maxi=max(maxi,grid[row][col]);
        //     pair<int,int>p;
        //     int mini=INT_MAX;
        //     for(int i=0;i<rowvec.size();i++){   
        //         int nr=row+rowvec[i];
        //         int nc=col+colvec[i];
        //         if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
        //             if(grid[nr][nc]<mini){
        //                 mini=grid[nr][nc];
        //                 p={nr,nc};
        //             }
        //         }
        //     }
        //     vis[p.first][p.second]=1;
        //     q.push({p.first,p.second});
        // }
        // return maxi;

        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];  // IMP
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int elevation=it.first;
            int elev=elevation;
            pq.pop();
            if(row==n-1 && col==n-1) break;
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr*dc!=0) continue;
                    int nr=row+dr;
                    int nc=col+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<n){
                        elev=max(elevation,grid[nr][nc]);
                        if(elev<dist[nr][nc]){
                            dist[nr][nc]=elev;
                            pq.push({elev,{nr,nc}});
                        }
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};