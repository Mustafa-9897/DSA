class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int premax=-1;
        vector<int>prefixgcd;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>premax) premax=nums[i];
            int currgcd=gcd(premax,nums[i]);
            prefixgcd.push_back(currgcd);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int l=0,r=prefixgcd.size()-1;
        long long sum=0;
        while(l<r){
            sum += gcd(prefixgcd[l],prefixgcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};