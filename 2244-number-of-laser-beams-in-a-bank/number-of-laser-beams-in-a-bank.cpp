class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>nums;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            string s=bank[i];
            for(int j=0;j<s.size();j++){
                if(s[j]=='1'){
                    cnt++;
                }
            }
            nums.push_back(cnt);
        }
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<nums.size();j++){
                ans += nums[i]*nums[j];
                if(nums[j]!=0) break;
            }
        }
        return ans;
    }
};