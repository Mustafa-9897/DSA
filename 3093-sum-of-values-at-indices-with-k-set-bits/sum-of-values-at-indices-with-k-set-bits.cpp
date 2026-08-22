class Solution {
public:
    int helper(int num){
        int cnt=0;
        while(num!=0){
            num = num & (num-1);
            cnt++;
        }
        return cnt;
        // int cnt=1;
        // while(num!=1){
        //     if(num%2==1) cnt++;
        //     num /= 2;
        // }
        // return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int setbits=helper(i);
            if(setbits==k){
                sum += nums[i];
            }
        }
        return sum;
    }
};