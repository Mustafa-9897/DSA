class Solution {
public:
    int findsum(int num){
        int ans=0;
        while(num!=0){
            ans += num%10;
            num /= 10;
        }
        return ans;
    }
    static bool comp(int a,int b){
        return a>b;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            int sum=findsum(nums[i]);
            mpp[sum].push_back(nums[i]);
        }
        int ans=-1;
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            vector<int>temp=it->second;
            if(temp.size()<2) continue;
            sort(temp.begin(),temp.end(),comp);
            ans=max(ans,temp[0]+temp[1]);
        }
        return ans;
    }
};