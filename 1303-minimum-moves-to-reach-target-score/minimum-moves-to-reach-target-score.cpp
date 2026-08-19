class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        while(target>1 && maxDoubles!=0){
            if(target%2==0){
                target /= 2;
                cnt++;
                maxDoubles--;
            }
            else{
                cnt++;
                target--;
            }
        }
        // if max doubles==0 to ham direct target me se 1 minus karenge ,utne operations karna hi padhega target ko 1 tak lane ke liye ,, aur agar upar while loop chal chuka hai to already target 1 ho gaya hoga so yahan pe cnt += 0 ho jayega so no extra steps are being added
        cnt += target-1;     
        return cnt;
    }
};