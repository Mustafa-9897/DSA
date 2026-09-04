class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            int mini=INT_MAX;
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
            }
            int diff=maxi-mini;
            if(diff<=k){
                ans=min(ans,i);
            }
        }
        if(ans!=INT_MAX){
            return ans;
        }
        return -1;
    }
};