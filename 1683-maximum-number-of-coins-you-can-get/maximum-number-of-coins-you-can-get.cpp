class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int cnt=piles.size()/3;
        int i=piles.size()-2;
        int ans=0;
        while(cnt){
            ans += piles[i];
            i -= 2;  // we will choose 2 elements from the last the largest , and the for bob from starting
            cnt--;
        }
        return ans;
    }
};