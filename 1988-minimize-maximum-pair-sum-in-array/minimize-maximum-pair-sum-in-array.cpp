class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int maxi=INT_MIN;
        while(l<r){
            maxi=max(maxi,nums[l]+nums[r]);
            l++;
            r--;
        }
        return maxi;
    }
};