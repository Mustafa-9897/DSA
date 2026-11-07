class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({passingFees[0],{0,0}});

        vector<int>dist(n,INT_MAX);
        dist[0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            int cost=it.first;
            int node=it.second.second;
            int d=it.second.first;
            pq.pop();
            if(node==n-1 && d<=maxTime) return cost;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                int fee=passingFees[adjnode];
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    pq.push({cost+fee,{d+wt,adjnode}});
                }
            }
        }
        return -1;
    }
};