class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size()!=t.size()){
        //     return false;
        // }
        // unordered_map<char,int>mpp1;
        // unordered_map<char,int>mpp2;
        // for(int i=0;i<s.size();i++){
        //     mpp1[s[i]]++;
        // }
        // for(int i=0;i<t.size();i++){
        //     mpp2[t[i]]++;           
        // }
        // return mpp1==mpp2;

        //    SLIGHT BETTER
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int>mpp;
        for(auto ch:s) mpp[ch]++;
        for(auto ch:t) mpp[ch]--;
        for(auto it:mpp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};