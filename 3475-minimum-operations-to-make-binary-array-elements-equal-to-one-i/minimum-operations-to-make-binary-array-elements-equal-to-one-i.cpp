class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                nums[i]=1;
                if(nums[i+1]==1) nums[i+1]=0;
                else nums[i+1]=1;
                if(nums[i+2]==1) nums[i+2]=0;
                else nums[i+2]=1;
                ans++;
            }
        }
        if(nums[n-1]==1 && nums[n-2]==1){
            return ans;
        }
        return -1;
    }
};