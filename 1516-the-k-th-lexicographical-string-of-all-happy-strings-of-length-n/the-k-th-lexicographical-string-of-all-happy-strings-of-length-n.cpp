class Solution {
public:
    string helper(string curr,int n,int &k){
        if(curr.size()==n){
            k--;
            if(k==0){
                return curr;
            }
            return "";
        }
        if(curr.empty() || curr.back()!='a'){
            string ans=helper(curr+'a',n,k);
            if(!ans.empty()) return ans;
        }
        if(curr.empty() || curr.back()!='b'){
            string ans=helper(curr+'b',n,k);
            if(!ans.empty()) return ans;
        }
        if(curr.empty() || curr.back()!='c'){
            string ans=helper(curr+'c',n,k);
            if(!ans.empty()) return ans;
        }
        return "";
    }
    string getHappyString(int n, int k) {
        return helper("",n,k);       
    }
};