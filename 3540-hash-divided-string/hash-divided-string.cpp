class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();
        vector<string>hash;
        string t="";
        int cnt=0;
        for(int i=0;i<n;i++){
            t += s[i];
            cnt++;
            if(cnt==k){
                cnt=0;
                hash.push_back(t);
                t.clear();
            }
        }
        string ans="";
        for(int i=0;i<hash.size();i++){
            int sum=0;
            for(int j=0;j<hash[i].size();j++){
                sum += int(hash[i][j]-'a');
            }
            int asc=sum%26;
            ans += char(asc+'a');
        }
        return ans;
    }
};