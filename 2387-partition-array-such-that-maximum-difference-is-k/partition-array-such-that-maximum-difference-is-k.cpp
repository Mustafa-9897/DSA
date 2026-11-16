class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            if(maxi-mini>k){
                ans++;
                mini=nums[i];
            }
        }
        ans++;
        return ans;
    }
};