class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int stones=n;
        int dec=10;
        int alice=1,bob=0;
        while(stones>=dec){
            if(alice==1){
                stones -= dec;
                dec--;
                alice=0;
                bob=1;
            }
            else if(bob==1){
                stones -= dec;
                dec--;
                bob=0;
                alice=1;
            }
        }
        if(alice==0) return true;
        return false;
    }
};