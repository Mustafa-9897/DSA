class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<groupSizes.size();i++){
            int size=groupSizes[i];
            mpp[size].push_back(i);
            if(mpp[size].size()==size){
                ans.push_back(mpp[size]);
                mpp[size].clear();
            }
        }
        return ans;
    }
};