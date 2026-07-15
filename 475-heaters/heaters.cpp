class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=heaters.size();
        int mindist=0,idx;
        int ans=0;
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<houses.size();i++){
            idx=lower_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin();
            if(idx==0) mindist=heaters[0]-houses[i];
            else if(idx==n) mindist=houses[i]-heaters[n-1];
            else mindist=min(heaters[idx]-houses[i],houses[i]-heaters[idx-1]);
            ans=max(ans,mindist);
        }
        return ans;
    }
};