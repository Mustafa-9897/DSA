class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans=0;
        for(long long i=1000;i<=n;){
            ans += n-i+1;
            if(i>n/1000){ // we are no doing i=i*1000 in for loop itself because when after i=10^15 then before ending the for loop , we will do i=i*1000 then it will become 10^18 then it will exceed long long too ,that is why we are doing it inside for loop and letting it exceed 10^15.           
                break;
            }
            i=i*1000;
        }
        return ans;
    }
};