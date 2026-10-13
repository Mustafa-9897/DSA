class Solution {
public:
    bool isprime(int num){
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    void helper(int n,vector<int>&ans,int s){
        int sum=0;
        for(int i=2;i<=n;i++){
            if(isprime(i)){
                sum += i;
                if(sum<=s){
                    ans.push_back(i);
                }
                else{
                    break;
                }
            }
        }
    }
    vector<int> maxPrimes(int n, int s) {
        // vector<int>ans;
        // helper(n,ans,s);
        // return ans;

        vector<int>ans;
        vector<bool>prime(n+1,true);
        if(n<=1) prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        int sum=0;
        for(int i=2;i<prime.size();i++){
            if(prime[i]){
                sum += i;
                if(sum<=s){
                    ans.push_back(i);
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};