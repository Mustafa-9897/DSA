class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>hash(501,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]%2==1){
                return false;
            }
        }
        return true;
    }
};