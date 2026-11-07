class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e5);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                }
            }
        }
        for(int i=1;i<dist.size();i++){
            if(dist[i]==1e5){
                return -1;
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};