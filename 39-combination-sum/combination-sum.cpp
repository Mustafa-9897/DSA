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
            //target -= nums[index]; // when i dexcrease target , it is correct for the pick choice but when after left side i go upwards to go to the left side (not pick) i already have decreased the target(change ho gaya target) so don't change tha target externally like this, do it inside the function call since in function call by decreasing we are not changing the value but just passing the reduced value
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