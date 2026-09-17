class Solution {
public:
    int characterReplacement(string s, int k) {
        //   BRUTE
        // int maxlen=0;
        // for(int i=0;i<s.size();i++){
        //     vector<int>hash(26,0);
        //     int maxfreq=0;
        //     for(int j=i;j<s.size();j++){
        //         hash[s[j]-'A']++;
        //         maxfreq=max(maxfreq,hash[s[j]-'A']);
        //         int changes=(j-i+1)-maxfreq;
        //         if(changes<=k){
        //             maxlen=max(maxlen,j-i+1);
        //         }
        //         else break;
        //     }
        // }
        // return maxlen;

        //  BETTER
        int l=0,r=0,maxlen=0,maxfreq=0;
        vector<int>hash(26,0);
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            while((r-l+1)-maxfreq>k){
                hash[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<hash.size();i++) maxfreq=max(maxfreq,hash[i]);
                l++;
            }
            if((r-l+1)-maxfreq<=k) maxlen=max(maxlen,r-l+1);
            r++; 
        }
        return maxlen;


        //   OPTIMAL
        // int l=0,r=0,maxlen=0;
        // unordered_map<int,int>mpp;
        // int maxfreq=0,changes;
        // while(r<s.size()){
        //     mpp[s[r]-'A']++;
        //     maxfreq=max(maxfreq,mpp[s[r]-'A']);
        //     changes=(r-l+1)-maxfreq;
        //     if(changes<=k){
        //         maxlen=max(maxlen,r-l+1);
        //     }
        //     else{
        //         mpp[s[l]-'A']--;
        //         l++;
        //     }
        //     r++;
        // }
        // return maxlen;
    }
};