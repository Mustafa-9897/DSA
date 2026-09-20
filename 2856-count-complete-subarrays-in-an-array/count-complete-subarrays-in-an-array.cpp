class Solution {
public:
    int helper(vector<int>&nums,int k){
        if(k<=0) return 0;
        int l=0,r=0;
        int ans=0;
        unordered_map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int k=st.size();
        return helper(nums,k)-helper(nums,k-1); // atmost k - atmost k-1
    }
};
