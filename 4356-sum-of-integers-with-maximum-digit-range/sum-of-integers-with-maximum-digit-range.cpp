class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxdiff=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int maxdigit=0;
            int mindigit=9;
            int q=nums[i];
            if(q==0){
                maxdigit=0;
                mindigit=0;
            }
            else{
                while(q>0){
                    int rem=q%10;
                    maxdigit=max(maxdigit,rem);
                    mindigit=min(mindigit,rem);
                    q /= 10;
                }
            }
            int range=maxdigit-mindigit;
            if(range>maxdiff){
                ans = nums[i];
                maxdiff=range;
            }
            else if(range==maxdiff){
                ans += nums[i];
            }
        }
        return ans;
    }
};