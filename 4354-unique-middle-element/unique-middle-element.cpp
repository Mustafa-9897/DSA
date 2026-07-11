class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        int midel=nums[n/2];
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]==midel || nums[r]==midel){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};