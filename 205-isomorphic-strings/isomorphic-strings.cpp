class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mpp1;
        map<char,char>mpp2;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mpp1.find(s[i])!=mpp1.end() && t[i]!=mpp1[s[i]]){
                return false;
            }
            if(mpp2.find(t[i])!=mpp2.end() && s[i]!=mpp2[t[i]]){
                return false;
            }          
            mpp1[s[i]]=t[i];   // we will have to check for both strings
            mpp2[t[i]]=s[i];
            
        }
        return true;
    }
};