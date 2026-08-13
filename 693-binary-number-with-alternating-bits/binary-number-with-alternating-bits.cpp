class Solution {
public:
    bool hasAlternatingBits(int n) {
        string res="";
        while(n!=1){
            if(n%2==1) res += '1';
            else res += '0';
            n /= 2;
        }
        res += '1';
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size()-1;i++){
            if(res[i+1]==res[i]){
                return false;
            }
        }
        return true;
    }
};