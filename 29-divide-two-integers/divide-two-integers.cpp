class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        bool sign=true;

        if(dividend>=0 && divisor<0) sign=false;
        else if(dividend<0 && divisor>0) sign=false;

        long n=abs((long)dividend);
        long d=abs((long)divisor);
        long ans=0;
        int cnt=0;

        while(n>=d){
            cnt=0;
            while(n>=d<<(cnt+1)){
                cnt++;
            }
            ans += 1LL<<cnt; // if we wrote 1<<cnt then if cnt=31 then it would get calculated in int which will overflow but 1LL<<cnt is calculated in long long so it won't overflow
            n -= d<<cnt;
        }

        if(ans>INT_MAX && sign==true) return INT_MAX;
        if(ans>INT_MAX && sign==false) return INT_MIN;
        return sign?ans:(-ans);  
    }
};