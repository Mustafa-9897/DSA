class Solution {
public:
    int countPrimes(int n) {
        // if(n<2) return 0;

        // //vector<int>prime(n,1); int takes 4 bit ,so instead use bool 1 bit

        // vector<bool>prime(n,true);
        // int cnt=0;
        // for(int i=2;i*i<prime.size();i++){
        //     if(prime[i]){
        //         for(int j=i*i;j<n;j+=i){
        //             prime[j]=false;
        //         }
        //     }
        // }
        // for(int i=2;i<prime.size();i++){
        //     if(prime[i]){
        //         cnt++;
        //     }
        // }
        // return cnt;

        if (n <= 2) return 0;

        vector<bool> composite(n, false); // composite numbers are numbers greater than 1 with more than 1 factors

        int cnt = 1; // prime number 2 , we counted 2  so do not have check any even number 

        for (int i = 3; i * i < n; i += 2) { // we will only check odd nums
            if (!composite[i]) { // means it does not have more than 1 factor , i.e prime
                for (int j = i * i; j < n; j += 2 * i) {
                    composite[j] = true;
                }
            }
        }

        for (int i = 3; i < n; i += 2) {  // only check odd nums
            if (!composite[i])
                cnt++;
        }

        return cnt;
    }
};
