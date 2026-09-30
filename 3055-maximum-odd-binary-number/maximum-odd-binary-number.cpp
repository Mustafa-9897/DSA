class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        string ans="";
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt1++;
        }
        cnt1 -= 1;
        for(int i=0;i<=n-2;i++){
            if(cnt1){
                ans += '1';
                cnt1--;
            }
            else{
                ans += '0';
            }
        }
        ans += '1';
        return ans;
    }
};