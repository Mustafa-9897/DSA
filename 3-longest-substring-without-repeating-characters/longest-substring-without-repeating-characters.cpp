class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //    BRUTE
        // int maxlen=0;
        // int len;
        // for(int i=0;i<s.size();i++){
        //     vector<int>hash(256,0);
        //     for(int j=i;j<s.size();j++){
        //         if(hash[s[j]]==1) break;
        //         len = j-i+1;
        //         hash[s[j]]=1;
        //     }
        //     maxlen=max(maxlen,len);
        // }
        // return maxlen;

        //   better
        // unordered_map<char, int> mpp;
        // int left = 0;
        // int ans = 0;
        // for (int right = 0; right < s.size(); right++) {
        //     while (mpp[s[right]] > 0) {
        //         mpp[s[left]]--;
        //         left++;
        //     }
        //     mpp[s[right]]++;
        //     ans = max(ans, right - left + 1);
        // }
        // return ans;


        // OPRIMAL
        vector<int>hash(256,-1);
        int len;
        int maxlen=0;
        int n=s.size();
        int left=0,right=0;
        while(right<n){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
            len=right-left+1;
            maxlen=max(maxlen,len);
            hash[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};