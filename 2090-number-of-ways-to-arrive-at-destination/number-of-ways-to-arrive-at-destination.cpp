class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=(int)1e9+7;

        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        vector<int>ways(n,0);
        ways[0]=1;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            long long d=it.first;
            pq.pop();

            if(d>dist[node]) continue; // if there are already {5,1} and {10,1} in the P_Q then we will first run over {5,1} whose cost is lesser and go to adj nodes of 1 with this short distance 5 and update the values of adj nodes but after this if ou encounter {10,1} then there is no meaning of going to adj nodes with this much cost when we have already done with smaller one beacuse with this large dist no adj node will accept this so instead don't go to save time

            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                // first time encounter
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    ways[adjnode]=ways[node];
                    pq.push({d+wt,adjnode});
                }
                // second time ecncounter with the same distance value
                else if(d+wt==dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};