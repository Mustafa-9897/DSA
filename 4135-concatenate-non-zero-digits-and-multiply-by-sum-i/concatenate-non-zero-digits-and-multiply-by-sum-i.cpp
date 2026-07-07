class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        int q=n;
        long long y=0;
        while(q!=0){
            int rem=q%10;
            sum += rem;
            q=q/10;
            if(rem!=0){
                y=y*10+rem;
            }
        }
        long long x=0;
        while(y!=0){
            int remainder=y%10;
            x=x*10+remainder;
            y=y/10;
        }
        long long ans=x*sum;
        return ans;
    }
};