class Solution {
public:
    bool checkDivisibility(int n) {
        int sum1=0;
        int sum2=1;
        int q=n;
        while(q!=0){
            int rem=q%10;
            sum1 += rem;
            sum2 *= rem;
            q /= 10;
        }
        int sum=sum1+sum2;
        return n%sum==0;
    }
};