class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        vector<int> ans;

        for(int x : nums) {
            int j = 0;

            while(temp[j] != x) {
                j++;
            }

            ans.push_back(j);
        }

        return ans;
    }
};