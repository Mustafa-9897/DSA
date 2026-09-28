class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
        }
        x = x^k;
        int ans=0;
        while(x>0){
            if(x%2==1) ans++;
            x = x/2;
        }
        return ans;
    }
};