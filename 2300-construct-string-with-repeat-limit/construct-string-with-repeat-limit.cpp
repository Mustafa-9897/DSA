class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        string ans="";
        int cnt=0;
        int i=25;
        int firsti=0;
        while(i>=0){
            if(hash[i]==0){
                continue;
            }
            cnt=0;
            while(hash[i]>0 && cnt<repeatLimit){
                ans += char('a'+i);
                cnt++;
                hash[i]--;
            }
            if(hash[i]>0){
                int j=i-1;
                while(j>=0 && hash[j]==0){
                    j--;
                }
                if(j<0){
                    break;
                }
                ans += char('a'+j);
                hash[j]--;
            }
            else{
                i--;
            }           
        }
        return ans;
    }
};