class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it=q.front();
            int node=it.second.first;
            int d=it.second.second;
            int stops=it.first;
            q.pop();

            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    q.push({stops+1,{adjnode,d+wt}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};