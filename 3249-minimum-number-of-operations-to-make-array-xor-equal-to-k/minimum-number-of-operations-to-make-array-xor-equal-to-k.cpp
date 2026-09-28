class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
        }

        x = x^k;   // x=nums[0]^nums[1]^nums[2]^.......^nums[n-1]
        int ans=0; // k= 01100010.... something
                   // so correspondingly in x the bits that are different from bits in k those 
                   // bits need to be changed

                   
        // while(x>0){
        //     if(x%2==1) ans++;            Method 1
        //     x = x/2;
        // }

        //return __builtin_popcount(x);     Method 2

        while(x>0){
            ans += x&1;
            x >>= 1;
        }

        return ans;
    }
};