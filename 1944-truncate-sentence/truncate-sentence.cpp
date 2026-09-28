class Solution {
public:
    string truncateSentence(string s, int k) {
        int i=0;
        int space=0;
        string ans="";
        while(i<s.size()){
            if(s[i]==' ') space++;
            if(space==k) break;
            ans += s[i];
            i++;
        }
        return ans;
    }
};