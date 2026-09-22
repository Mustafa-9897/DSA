class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxind){ // if the current indxe is bigger than the max index then it means that we were not able to reach that index , so just return false;
                return false;
            }
            maxind=max(maxind,i+nums[i]); // maintain max index that we can reach 
            
            if(maxind>=nums.size()-1)
                return true;
        }
        return true;
    }
};