class Solution {
public:
    int helper(int num){
        int cnt=0;
        while(num!=1){
            if(num%2==1) cnt++;
            num=num>>1;
        }
        cnt++;
        return cnt;
    }
    bool checkifprime(int num){
        if(num<2) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++){
            int ones=helper(i);
            if(checkifprime(ones)){
                cnt++;
            }
        }
        return cnt;
    }
};