class Solution {
public:
    void helper(int index,int k,vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums){
        if(curr.size()==k){
            ans.push_back(curr);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            helper(i+1,k,ans,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        vector<vector<int>>ans;
        vector<int>curr;
        helper(0,k,ans,curr,nums);
        return ans;
    }
};