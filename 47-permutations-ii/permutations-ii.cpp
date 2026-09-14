class Solution {
public:
    void helper(int index,set<vector<int>>&st,vector<int>&curr,vector<bool>&used,vector<int>&nums){
        if(curr.size()==nums.size()){
            st.insert(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==false){
                curr.push_back(nums[i]);
                used[i]=true;
                helper(i+1,st,curr,used,nums);
                curr.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        set<vector<int>>st;
        vector<bool>used(nums.size(),false);
        helper(0,st,curr,used,nums);
        ans.assign(st.begin(),st.end());
        return ans;
    }
};