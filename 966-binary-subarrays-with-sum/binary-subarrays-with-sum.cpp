class Solution {
public:
    int helper(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int l=0,r=0,cnt=0,sum=0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //   BRUTE WILL GIVE TLE
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum += nums[j];
        //         if(sum==goal){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;


        //  OPTIMAL
        return (helper(nums,goal)-helper(nums,goal-1));
    }
};