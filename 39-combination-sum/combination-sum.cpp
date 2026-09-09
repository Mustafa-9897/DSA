class Solution {
public:
    void helper(int index,int target,vector<vector<int>>&ans,vector<int>curr,vector<int>&nums)
    { 
        if(index==nums.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        if(target>=nums[index]){
            //target -= nums[index];
            curr.push_back(nums[index]);
            helper(index,target-nums[index],ans,curr,nums);
            curr.pop_back();
        }

        helper(index+1,target,ans,curr,nums);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(0,target,ans,curr,candidates);
        return ans;
    }
};