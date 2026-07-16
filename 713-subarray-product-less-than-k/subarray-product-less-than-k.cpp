class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // int cnt=0;
        // int product=1;
        // for(int i=0;i<nums.size();i++){
        //     product=1;
        //     for(int j=i;j<nums.size();j++){
        //         product = product*nums[j];          // BRUTE
        //         if(product<k) cnt++;
        //         else break;
        //     }
        // }
        // return cnt;

        // OPTIMAL
        int l=0,r=0;
        int product=1,cnt=0;
        while(r<nums.size()){
            product *= nums[r];
            while(product>=k){
                product /= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};