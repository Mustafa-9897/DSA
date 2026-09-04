class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mpp;
        for(int i=0;i<jewels.size();i++){
            mpp[jewels[i]]=1;
        }
        int ans=0;
        for(int i=0;i<stones.size();i++){
            if(mpp.find(stones[i])!=mpp.end()){
                ans++;
            }
        }
        return ans;
    }
};