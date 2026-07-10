class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int GCD=nums[0];
        for(auto it : nums){
            GCD=gcd(GCD,it);
            if(GCD==1){       // if and only if the gcd of all the elements of nums is 1 then
                return true;  // only the ans will be true , otherwise not
            }
        }
        return false;
    }
};