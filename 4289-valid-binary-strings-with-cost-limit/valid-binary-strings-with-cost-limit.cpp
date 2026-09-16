class Solution {
public:
    void helper(vector<string>&ans,string s,int cost,int k,int n,int index){
        if(s.size()==n){
            if(cost<=k){
                ans.push_back(s);
            }
            return ;
        }
        helper(ans,s+'0',cost,k,n,index+1);
        if(s.empty() || s.back()!='1'){
            helper(ans,s+'1',cost+index,k,n,index+1);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        helper(ans,"",0,k,n,0);
        return ans;
    }
};