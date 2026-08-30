class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool>ans(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(candies[i],maxi);
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};