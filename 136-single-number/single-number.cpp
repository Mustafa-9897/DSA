class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //  BRUTE
        // unordered_map<int,int>mpp;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it : mpp){
        //     if(it.second==1){
        //         return it.first;
        //     }
        // }
        // return 0;

        //   OPTIMAL
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;      
    }
};