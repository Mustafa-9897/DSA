class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        long long g,l,prod,n=nums.size();
        for(int i=0;i<n;i++){
            prod=1;
            g=0;
            l=1;
            for(int j=i;j<n;j++){
                prod=prod*nums[j];

                // since gcd*lcm is at most 2520  for (1-10)
                // since gcd*lcm<=2520
                if(prod>2520) break;

                g=gcd(g,(long long)nums[j]);
                l=l/gcd(l,(long long)nums[j])*nums[j];  // lcm(a,b)=(a*b)/gcd(a,b) but to prevent the overflow of a*b we first divide then multiply (a/gcd(a,b))*b 

                if(prod==g*l){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};