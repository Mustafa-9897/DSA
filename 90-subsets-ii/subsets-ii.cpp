class Solution {
public:
    void helper(int index,set<vector<int>>&st,vector<int>&curr,vector<int>&nums){
        if(index==nums.size()){
            st.insert(curr);
            return ;
        }
        curr.push_back(nums[index]);
        helper(index+1,st,curr,nums);
        curr.pop_back();
        helper(index+1,st,curr,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        helper(0,st,curr,nums);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};