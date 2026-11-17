class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        int sum=n;
        if(sum==k) return ans;
        int rem=k-n;
        for(int i=n-1;i>=0;i--){
            if(rem==0) break;
            int curr=min(25,rem);
            char ch=curr+'a';
            ans[i]=ch;
            rem -= curr;
        }
        return ans;
    }
};