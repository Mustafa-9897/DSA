class Solution {
public:
    int helper(string s,int i,long long ans,int sign){
        // if string ends or we are at non digit then return
        if(i>s.size() || !isdigit(s[i])){
            return sign*ans;
        }
        ans = ans*10 + s[i]-'0'; // to convert char into int
        if(sign*ans>=INT_MAX) return INT_MAX;
        if(sign*ans<=INT_MIN) return INT_MIN;
        return helper(s,i+1,ans,sign);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            sign = (s[i]=='-') ? -1 : 1;
            i++;
        }
        return helper(s,i,0,sign);

        // int i = 0;
        // int n = s.size();

        // // 1. Skip leading spaces
        // while (i < n && s[i] == ' ') {
        //     i++;
        // }

        // // 2. Check sign
        // int sign = 1;
        // if (i < n && (s[i] == '+' || s[i] == '-')) {  // this checks if there are any signs 
        //     if (s[i] == '-') {                        // before the number starts
        //         sign = -1;
        //     }
        //     i++;
        // }

        // // 3. Convert digits
        // int ans = 0;
        // while (i < n && isdigit(s[i])) {
        //     int digit = s[i] - '0';

        //     // 4. Check overflow
        //     if (ans > (INT_MAX - digit) / 10) {
        //         return (sign == 1) ? INT_MAX : INT_MIN;
        //     }

        //     ans = ans * 10 + digit;
        //     i++;
        // }

        // return sign * ans;
    }
};