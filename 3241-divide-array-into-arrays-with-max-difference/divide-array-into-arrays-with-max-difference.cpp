class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(temp.size()>0 && nums[i]-temp[0]>k) { // we will check the the difference between the largesxt and the smallest element if it is greter than k then not possible , don't compare nums[i] with temp.back()
                return {};
            }
            temp.push_back(nums[i]);
            if((i+1)%3==0){
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};