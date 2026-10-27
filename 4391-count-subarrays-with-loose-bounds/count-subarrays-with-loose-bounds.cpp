class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // long long cnt=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     vector<vector<int>>ans;
        //     vector<int>temp;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]>=minK && nums[j]<=maxK){
        //             temp.push_back(nums[j]);
        //         }
        //         else break;
        //         ans.push_back(temp);
        //     }
        //     cnt += ans.size();
        // }
        // return cnt;

        long long ans=0;
        long long cnt=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]>=minK && nums[i]<=maxK) cnt++;
            else{
                ans += (long long)(cnt)*(long long)(cnt+1)/2;
                cnt=0;
            }
            i++;
        }
        ans += (long long)(cnt)*(long long)(cnt+1)/2;
        return ans;
    }
};