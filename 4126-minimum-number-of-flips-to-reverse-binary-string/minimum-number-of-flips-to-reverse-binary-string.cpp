class Solution {
public:
    int minimumFlips(int n) {
        string res1="";
        while(n!=1){
            if(n%2==1) res1 += '1';
            else res1 += '0';
            n=n/2; 
        }
        res1 += '1';
        string res2="";
        for(int i=res1.size()-1;i>=0;i--){
            res2 += res1[i];
        }
        int cnt=0;
        for(int i=0;i<res1.size();i++){
            if(res1[i]!=res2[i]) cnt++;
        }
        return cnt;
    }
};