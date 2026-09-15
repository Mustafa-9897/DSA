class Solution {
public:
    void helper(int index,vector<string>&ans,string curr,vector<bool>&used,vector<int>&nums){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==false){
                curr += nums[i]+'0';
                used[i]=true;
                helper(i+1,ans,curr,used,nums);
                curr.pop_back();
                used[i]=false;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<string>ans;
        string curr="";
        vector<bool>used(n,false);
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        helper(0,ans,curr,used,nums);
        string s;
        for(int i=0;i<ans.size();i++){
            if(i==k-1){
                s=ans[i];
                break;
            }
        }
        return s;
    }
};