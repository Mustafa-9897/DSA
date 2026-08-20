class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        arr1.push_back(nums[0]);
        vector<int>arr2;
        arr2.push_back(nums[1]);
        vector<int>result;
        for(int k=2;k<nums.size();k++){
            if(arr1.back()>arr2.back()){
                arr1.push_back(nums[k]);
            }
            else{
                arr2.push_back(nums[k]);
            }
        }
        for(int i=0;i<arr1.size();i++){
            result.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            result.push_back(arr2[i]);
        }
        return result;
    }
};