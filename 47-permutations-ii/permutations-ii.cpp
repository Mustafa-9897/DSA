class Solution {
public:
    // void helper(int index,set<vector<int>>&st,vector<int>&curr,vector<bool>&used,vector<int>&nums){
    //     if(curr.size()==nums.size()){
    //         st.insert(curr);
    //         return ;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(used[i]==false){
    //             curr.push_back(nums[i]);        //  BRUTE
    //             used[i]=true;
    //             helper(i+1,st,curr,used,nums);
    //             curr.pop_back();
    //             used[i]=false;
    //         }
    //     }
    // }
    void helper(vector<vector<int>>&ans,vector<int>&curr,vector<bool>&used,vector<int>&nums){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++){

            if(used[i]==true) continue;   
            // means if the previous elment is used , and now the current element is same as previous then continue,or else duplicates will get formed
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            
            used[i]=true;
            curr.push_back(nums[i]);
            helper(ans,curr,used,nums);
            used[i]=false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // vector<vector<int>>ans;
        // vector<int>curr;
        // set<vector<int>>st;
        // vector<bool>used(nums.size(),false);   // BRUTE
        // helper(0,st,curr,used,nums);
        // ans.assign(st.begin(),st.end());
        // return ans;

        //  OPTIMAL
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool>used(nums.size(),false);
        sort(nums.begin(),nums.end());
        helper(ans,curr,used,nums);
        return ans;
    }
};