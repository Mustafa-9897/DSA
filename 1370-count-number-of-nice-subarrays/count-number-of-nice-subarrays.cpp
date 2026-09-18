class Solution {
public:
    int helper(vector<int>&nums,int k){
        if(k<0) return 0;
        int cnt=0,l=0,r=0,ans=0;
        while(r<nums.size()){
            if(nums[r]%2==1) cnt++;
            while(cnt>k){
                if(nums[l]%2==1) cnt--;
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (helper(nums,k)-helper(nums,k-1));
    }
};