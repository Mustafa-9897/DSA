class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s(num,'0');
        if(num*9<sum) return "";
        int currnum=9;
        int currsum=0;
        for(int i=0;i<num;i++){
            s[i] = currnum+'0';
            currsum += s[i]-'0';
            while(currsum>sum){
                currsum--;
                if(currnum>0) currnum--;
            }
            s[i]=currnum+'0';
        }
        return s;
    }
};