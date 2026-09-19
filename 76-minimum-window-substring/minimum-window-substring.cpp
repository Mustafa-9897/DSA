class Solution {
public:
    string minWindow(string s, string t) {
        //   BRUTE WILL GIVE TLE
        // int minlen=INT_MAX;
        // int startingidx=-1;
        // for(int i=0;i<s.size();i++){
        //     int cnt=0;
        //     unordered_map<char,int>mpp;
        //     for(int j=0;j<t.size();j++) mpp[t[j]]++;
        //     for(int j=i;j<s.size();j++){
        //         if(mpp[s[j]]>0) cnt++;
        //         mpp[s[j]]--;
        //         if(cnt==t.size()){
        //             if(j-i+1<minlen){
        //                 minlen=j-i+1;
        //                 startingidx=i;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // if(startingidx==-1) return "";
        // return s.substr(startingidx,minlen);

        unordered_map<char,int>mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int l=0,r=0,cnt=0,stidx=-1,minlen=INT_MAX;
        while(r<s.size()){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    stidx=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(stidx==-1) return "";
        return s.substr(stidx,minlen);
    }
};