class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int inc=1;
        int dec=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            inc=1;
            for(int j=i;j<n-1;j++){
                if(nums[j+1]>nums[j]) inc++;
                else break;
                ans=max(ans,inc);
            }
        }
        for(int i=0;i<n;i++){
            dec=1;
            for(int j=i;j<n-1;j++){
                if(nums[j+1]<nums[j]) dec++;
                else break;
                ans=max(ans,dec);
            }
        }
        return ans;
    }
};