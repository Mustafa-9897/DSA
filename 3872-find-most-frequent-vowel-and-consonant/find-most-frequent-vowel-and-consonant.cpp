class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>hash(26);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        for(int i=0;i<hash.size();i++){
            if(i=='a'-'a' || i=='e'-'a' || i=='i'-'a' || i=='o'-'a' || i=='u'-'a'){
                maxi1=max(maxi1,hash[i]);
            }
            else{
                maxi2=max(maxi2,hash[i]);
            }
        }
        return maxi1+maxi2;
    }
};