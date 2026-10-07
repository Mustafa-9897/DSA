class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]>1) arr[0]=1;
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            int diff=arr[i]-arr[i-1];
            if(diff>1){
                arr[i]=arr[i-1]+1;
            }
            maxi=max(maxi,arr[i]);
        }
        // int maxi=INT_MIN;
        // for(int i=0;i<arr.size();i++){
        //     maxi=max(maxi,arr[i]);
        // }
        return maxi;
    }
};