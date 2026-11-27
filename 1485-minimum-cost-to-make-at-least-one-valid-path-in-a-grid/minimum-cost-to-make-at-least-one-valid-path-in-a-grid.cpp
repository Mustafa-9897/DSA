class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>adj(n*m);

        unordered_map<int,pair<int,int>>mpp={
            {1,{0,1}} , {2,{0,-1}} ,
            {3,{1,0}} , {4,{-1,0}}
        };
        int cost;
        vector<int>r={0,-1,0,1};
        vector<int>c={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int node=m*i+j;
                int code=grid[i][j];
                pair<int,int>p=mpp[code];
                //int realadjnode=(i+p.first)*m+(j+p.second);
                for(int k=0;k<4;k++){
                    int nr=i+r[k];
                    int nc=j+c[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        int adjnode=nr*m+nc;
                        if(r[k]==p.first && c[k]==p.second){
                            cost=0;
                        }
                        else cost=1;
                        adj[node].push_back({adjnode,cost});
                    }
                }
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>dist(n*m,INT_MAX);
        dist[0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;

            if(wt>dist[node]) continue;

            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[adjnode]){
                    dist[adjnode]=dist[node]+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist[m*n-1];
    }
};