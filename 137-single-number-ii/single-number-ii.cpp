class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //   BRUTE
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


        // BETTER
        int ans=0;
        for(int bitidx=0;bitidx<=31;bitidx++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<bitidx)){
                    cnt++;
                }
            }
            if(cnt%3==1){
                ans = ans | (1<<bitidx);
            }
        }
        return ans;
    }
};