class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int cnt=piles.size()/3;
        int i=piles.size()-2;
        int ans=0;
        while(cnt){
            ans += piles[i];
            i -= 2;
            cnt--;
        }
        return ans;
    }
};