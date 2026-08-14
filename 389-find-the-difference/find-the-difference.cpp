class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>t1(26,0);
        vector<int>t2(26,0);
        for(int i=0;i<t.size();i++){
            t2[t[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            t1[s[i]-'a']++;
        }
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                return char(i+'a');
            }
        }
        return 'a';
    }
};