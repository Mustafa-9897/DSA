class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int left=0,right=0;
        int n1=nums1.size(),n2=nums2.size();
        int maxi=0;
        while(left<n1 && right<n2){           
            if(nums1[left]<=nums2[right]){
                maxi=max(maxi,right-left);
                right++;
            }
            else{
                left++;
            }
            
        }
        return maxi;
    }
};