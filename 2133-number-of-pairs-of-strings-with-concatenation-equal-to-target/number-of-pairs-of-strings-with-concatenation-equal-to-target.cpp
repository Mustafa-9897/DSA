class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string s=nums[i];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(s+nums[j]==target) ans++;
            }
        }
        return ans;
    }
};