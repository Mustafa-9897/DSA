class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        int t1=num1.size()-1;
        int t2=num2.size()-1;
        int sum;
        string ans="";
        while(t1>=0 || t2>=0){
            sum=carry;
            if(t1>=0) sum += num1[t1]-'0';// num[t1] will be a char like '5' or '6' so to 
            if(t2>=0) sum += num2[t2]-'0';//convert it to integer subtract the ASCII value of 0
            ans += char(sum%10 + '0');  
            carry=sum/10;
            t1--;
            t2--;
        }
        if(carry!=0){
            ans += char(carry + '0'); // this is the method of converting a integer into char
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};