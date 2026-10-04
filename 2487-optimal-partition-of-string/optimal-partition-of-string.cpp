class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mpp;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                ans++;
                mpp.clear();
                mpp[s[i]]=1;
            }
            else{
                mpp[s[i]]=1;
            }
        }
        return ans+1;
    }
};