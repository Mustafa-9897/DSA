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

        vector<bool> composite(n, false);

        int cnt = 1; // prime number 2

        for (int i = 3; i * i < n; i += 2) {
            if (!composite[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    composite[j] = true;
                }
            }
        }

        for (int i = 3; i < n; i += 2) {
            if (!composite[i])
                cnt++;
        }

        return cnt;
    }
};
