class Solution {
public:
    int helper(vector<int>&freq){
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            freq[i]--;
            ans += 1 + helper(freq);
            freq[i]++;
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        for(int i=0;i<tiles.size();i++){
            freq[tiles[i]-'A']++;
        }
        return helper(freq);
    }
};