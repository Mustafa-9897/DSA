class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //BRUTE
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(nums[j]<nums[i]){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;

        //OPTIMAL
        // vector<int> temp = nums;
        // sort(temp.begin(), temp.end());
        // vector<int> ans;
        // for(int x : nums) {
        //     int j = 0;
        //     while(temp[j] != x) {
        //         j++;
        //     }
        //     ans.push_back(j);
        // }
        // return ans;
    }
};