class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        while(nums.size()!=1){
            int n=nums.size();
            vector<int>temp(n-1);
            for(int i=0;i<n-1;i++){
                temp[i]=((nums[i]+nums[i+1])%10);
            }
            nums=temp;
        }
        return nums[0];
    }
};