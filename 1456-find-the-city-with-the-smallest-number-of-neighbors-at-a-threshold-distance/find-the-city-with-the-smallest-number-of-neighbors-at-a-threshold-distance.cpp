class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>cost(n,vector<int>(n,1e5));
        for(int i=0;i<n;i++){
            cost[i][i]=0;
        }
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        vector<int>frq(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold){
                    frq[i]++;
                }
            }
        }
        int cities=INT_MAX;
        int ans=0;
        for(int i=0;i<frq.size();i++){
            if(frq[i]<=cities){
                cities=frq[i];
                ans=i;
            }
        }
        return ans;
    }
};