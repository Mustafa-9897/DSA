class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            int q=nums[i];
            while(q!=0){
                int rem=q%10;
                temp.push_back(rem);
                q /= 10;
            }
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++){
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};