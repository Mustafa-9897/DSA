class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=n-1;
        while(s[i]==' ' && i>=0){
            i--;
        }
        int ans=0;
        while(i>=0){
            if(s[i]==' ') break;
            ans++;
            i--;
        }
        return ans;
    }
};