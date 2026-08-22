class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0;
        int odd=0;
        int cnt=0;
        while(n!=0){
            if(n%2==1 && cnt%2==0) even++;
            if(n%2==1 && cnt%2==1) odd++;
            n /= 2;
            cnt++;
        }
        return {even,odd};
    }
};