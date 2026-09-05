class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n);
        vector<int>mini(n);
        int ans=INT_MAX;
        mini[n-1]=nums[n-1];
        maxi[0]=nums[0];
        for(int i=1;i<n;i++){
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            mini[i]=min(mini[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k){
                ans=min(ans,i);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};