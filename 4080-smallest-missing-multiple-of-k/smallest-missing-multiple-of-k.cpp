class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // vector<int>hash(101,0);
        // for(int i=0;i<nums.size();i++){
        //     hash[nums[i]]++;
        // }
        // for(int i=k;i<hash.size();i+=k){
        //     if(hash[i]==0) return i;
        // }
        // return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = k; ; i += k) {
            if(s.find(i) == s.end())
                return i;
        }
    }
};