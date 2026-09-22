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
        // int ans2=0;
        // for(int i=0;i<m;i++){
        //     vector<int>column;
        //     for(int j=0;j<n;j++){
        //         column.push_back(grid[j][i]);   //   BRUTE
        //     }
        //     ans2 += helper(column);
        // }

        int ans2=0;
        for(int j=0;j<m;j++){
            int top=0,bottom=n-1;
            while(top<bottom){
                if(grid[top][j]!=grid[bottom][j]) ans2++;
                top++;
                bottom--;
            }
        }
        return min(ans1,ans2);
    }
};