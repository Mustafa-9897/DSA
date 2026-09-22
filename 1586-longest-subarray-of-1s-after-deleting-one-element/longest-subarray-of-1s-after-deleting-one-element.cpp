class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0;
        int maxlen=INT_MIN;
        int cnt=0;
        while(r<nums.size()){
            if(nums[r]==0){
                cnt++;
            }
            while(cnt>1){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l);
            r++;
        }
        return maxlen;
    }
};