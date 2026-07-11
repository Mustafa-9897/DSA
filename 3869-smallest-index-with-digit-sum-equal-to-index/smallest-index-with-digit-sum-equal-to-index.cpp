class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int sum;
        for(int i=0;i<nums.size();i++){
            sum=0;
            int q=nums[i];
            while(q>0){
                int rem=q%10;
                sum += rem;
                q = q/10;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};