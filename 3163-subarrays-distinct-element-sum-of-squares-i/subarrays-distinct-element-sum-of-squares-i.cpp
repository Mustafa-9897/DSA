class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mpp;
            for(int j=i;j<n;j++){
                if(mpp.find(nums[j])==mpp.end()){
                    mpp[nums[j]]=1;
                }
                int size=mpp.size();
                sum += size*size;
            }
        }
        return sum;
    }
};