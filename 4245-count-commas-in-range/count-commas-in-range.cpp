class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int ans=0;
        for(int i=1000;i<=n;i++){
            int num=i;
            int cnt=0;
            while(num!=0){
                cnt++;
                num /= 10;
            }
            if(cnt%3==0){
                ans += cnt/3-1;
            }
            else{
                ans += cnt/3;
            }
        }
        return ans;
    }
};