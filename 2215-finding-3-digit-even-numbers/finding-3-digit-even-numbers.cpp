class Solution {
public:
    void helper(int index,vector<int>&ans,int num,vector<int>&digits,vector<bool>&used,int len){
        if(len==3){
            if(num%2==0){
                ans.push_back(num);
            }
            return ;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i]) continue;
            if(i>index && digits[i]==digits[i-1] && !used[i-1]) continue;
            if(len==0 && digits[i]==0) continue;
            used[i]=true;
            helper(i+1,ans,num*10+digits[i],digits,used,len+1);
            used[i]=false;
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
        vector<int>ans;
        vector<bool>used(digits.size(),false);
        helper(0,ans,0,digits,used,0);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};