class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // BRUTE
        // int len,maxlen=0;
        // for(int i=0;i<nums.size();i++){
        //     int zeroes=0;
        //     for(int j=i;j<nums.size();j++){   // will give TLE
        //         if(nums[j]==0) zeroes++;
        //         if(zeroes>k) break;
        //         maxlen=max(maxlen,j-i+1);
        //     }
        // }
        // return maxlen;

        // BETTER
        int l=0,r=0;
        int zeroes=0;
        int maxlen=0;
        while(r<nums.size()){
            if(nums[r]==0)
                zeroes++;
            while(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};