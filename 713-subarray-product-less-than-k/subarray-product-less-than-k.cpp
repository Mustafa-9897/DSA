class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        int product=1;
        for(int i=0;i<nums.size();i++){
            product=1;
            for(int j=i;j<nums.size();j++){
                product = product*nums[j];
                if(product<k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};