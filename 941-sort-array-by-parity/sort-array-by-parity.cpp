class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>even;
        // vector<int>odd;
        // vector<int>ans(n);
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==0){
        //         even.push_back(nums[i]);
        //     }
        //     else{
        //         odd.push_back(nums[i]);          //very very BRUTE
        //     }
        // }
        // for(int i=0;i<even.size();i++){
        //     ans[i]=even[i];
        // }
        // int j=even.size();
        // for(int i=0;i<odd.size();i++){
        //     ans[j]=odd[i];
        //     j++;
        // }
        // return ans;

        //  OPTIMAL
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>ans(n);
        for(int k=0;k<n;k++){
            if(nums[k]%2==0){
                ans[i]=nums[k];
                i++;
            }
            else{
                ans[j]=nums[k];
                j--;
            }
        }
        return ans;
    }
};