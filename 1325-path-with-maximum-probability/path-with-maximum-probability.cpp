class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pair<double,int>>pq;
        pq.push({1,start_node});

        vector<double>dist(n,0);
        dist[start_node]=1;

        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            double p=it.first;
            pq.pop();
            if(node==end_node) break;
            for(auto it:adj[node]){
                int adjnode=it.first;
                double prob=it.second;
                if(p*prob>dist[adjnode]){
                    dist[adjnode]=p*prob;
                    pq.push({p*prob,adjnode});
                }
            }
        }
        return dist[end_node];
    }
};