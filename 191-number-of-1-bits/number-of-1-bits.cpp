class Solution {
public:
    int hammingWeight(int n) {
        int cnt=1;
        while(n!=1){
            if(n%2==1) cnt += 1;
            n /= 2;
        }
        return cnt;
    }
};