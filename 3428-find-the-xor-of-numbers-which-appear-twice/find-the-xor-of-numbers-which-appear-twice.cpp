class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int>hash(51,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<hash.size();i++){
            if(hash[i]==2){
                ans ^= i;
            }
        }
        return ans;
    }
};