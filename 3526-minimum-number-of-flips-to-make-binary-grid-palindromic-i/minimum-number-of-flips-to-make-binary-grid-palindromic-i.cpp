class Solution {
public:
    int helper(vector<int>&nums){
        int ans=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]!=nums[j]){
                ans++;
            }
            i++;
            j--;
        }
        return ans;
    }
    int minFlips(vector<vector<int>>& grid) {
        int ans1=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            ans1 += helper(grid[i]);
        }
        int ans2=0;
        for(int i=0;i<m;i++){
            vector<int>column;
            for(int j=0;j<n;j++){
                column.push_back(grid[j][i]);
            }
            ans2 += helper(column);
        }
        return min(ans1,ans2);
    }
};