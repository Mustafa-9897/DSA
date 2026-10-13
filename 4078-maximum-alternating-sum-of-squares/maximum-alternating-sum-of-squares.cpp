class Solution {
public:
    static bool comparator(int a,int b){
        return abs(a)<abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comparator);
        int n=nums.size();
        int i=0;
        int j=n-1;
        int even=0;
        int odd=1;
        vector<int>temp(n);
        while(i<=j && (even<n || odd<n)){
            if(even<n)
                temp[even]=nums[j];
            if(odd<n)
                temp[odd]=nums[i];
            even += 2;
            odd += 2;
            i++;
            j--;
        }
        long long ans=0;
        for(int i=0;i<temp.size();i++){
            if(i%2==0)
                ans += (long long)temp[i]*(long long)temp[i];
            else 
                ans -= (long long)temp[i]*(long long)temp[i];
        }
        return ans;
    }
};