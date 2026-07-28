class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<abs(ans) || abs(nums[i])==abs(ans) && nums[i]>ans){
                ans=nums[i];
            }
        }
       return ans;
    }
};