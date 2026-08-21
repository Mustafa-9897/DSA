class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans(pref.size());
        ans[0]=pref[0];
        int prexor=pref[0];
        for(int i=1;i<pref.size();i++){
            ans[i]=prexor^pref[i];
            prexor ^= ans[i];
        }
        return ans;
    }
};