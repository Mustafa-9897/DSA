class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(201,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int cnt=n;
        vector<vector<int>>ans;
        while(cnt){
            vector<int>temp;
            for(int i=0;i<hash.size();i++){
                if(hash[i]!=0){
                    temp.push_back(i);
                    hash[i]--;
                    cnt--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};