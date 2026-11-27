class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // int n=grid.size(),m=grid[0].size();
        // vector<vector<pair<int,int>>>adj(n*m);

        // unordered_map<int,pair<int,int>>mpp={
        //     {1,{0,1}} , {2,{0,-1}} ,
        //     {3,{1,0}} , {4,{-1,0}}
        // };
        // int cost;
        // vector<int>r={0,-1,0,1};
        // vector<int>c={-1,0,1,0};
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int node=m*i+j;
        //         int code=grid[i][j];
        //         pair<int,int>p=mpp[code];

        //         for(int k=0;k<4;k++){
        //             int nr=i+r[k];
        //             int nc=j+c[k];
        //             if(nr>=0 && nr<n && nc>=0 && nc<m){
        //                 int adjnode=nr*m+nc;
        //                 if(r[k]==p.first && c[k]==p.second){
        //                     cost=0;
        //                 }
        //                 else cost=1;
        //                 adj[node].push_back({adjnode,cost});
        //             }
        //         }
        //     }
        // }

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // pq.push({0,0});
        // vector<int>dist(n*m,INT_MAX);
        // dist[0]=0;

        // while(!pq.empty()){
        //     auto it=pq.top();
        //     pq.pop();
        //     int node=it.second;
        //     int wt=it.first;

        //     if(wt>dist[node]) continue;

        //     for(auto it:adj[node]){
        //         int adjnode=it.first;
        //         int wt=it.second;
        //         if(dist[node]+wt<dist[adjnode]){
        //             dist[adjnode]=dist[node]+wt;
        //             pq.push({dist[adjnode],adjnode});
        //         }
        //     }
        // }
        // return dist[m*n-1];


        // OPTIMAL USING 0-1 BFS
        int n = grid.size(), m = grid[0].size();
        // index matches sign: 1=right, 2=left, 3=down, 4=up
        int dr[5] = {0, 0, 0, 1, -1};
        int dc[5] = {0, 1, -1, 0, 0};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0] = 0;
        dq.push_back({0, 0});

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (int d = 1; d <= 4; d++) {
                int ni = i + dr[d], nj = j + dc[d];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                int cost = (grid[i][j] == d) ? 0 : 1;
                if (dist[i][j] + cost < dist[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + cost;
                    if (cost == 0) dq.push_front({ni, nj});
                    else dq.push_back({ni, nj});
                }
            }
        }
        return dist[n-1][m-1];
    }
};