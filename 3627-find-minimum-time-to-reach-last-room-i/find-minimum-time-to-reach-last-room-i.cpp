class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        time[0][0]=0;

        vector<int>r={0,-1,0,1};
        vector<int>c={-1,0,1,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1) break;
            if(t>time[row][col]) continue;
            for(int i=0;i<4;i++){
                int nr=row+r[i];
                int nc=col+c[i];
                if(nr<n && nr>=0 && nc>=0 && nc<m){
                    if(time[nr][nc]>max(moveTime[nr][nc]+1,time[row][col]+1)){
                        time[nr][nc]=max(moveTime[nr][nc]+1,time[row][col]+1);
                        pq.push({time[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return time[n-1][m-1];
    }
};