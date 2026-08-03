class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left=0,right=0;
        int n=nums.size();
        vector<int>leftsum(n);
        vector<int>rightsum(n);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            leftsum[i]=left;
            left += nums[i];
            rightsum[n-i-1]=right;
            right += nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(leftsum[i]-rightsum[i]);
        }
        return ans;
    }
};