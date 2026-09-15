class Solution {
public:
    // string helper(string curr,int n,int &k){
    //     if(curr.size()==n){
    //         k--;
    //         if(k==0){
    //             return curr;
    //         }
    //         return "";
    //     }
    //     if(curr.empty() || curr.back()!='a'){
    //         string ans=helper(curr+'a',n,k);
    //         if(!ans.empty()) return ans;
    //     }
    //     if(curr.empty() || curr.back()!='b'){
    //         string ans=helper(curr+'b',n,k);
    //         if(!ans.empty()) return ans;
    //     }
    //     if(curr.empty() || curr.back()!='c'){
    //         string ans=helper(curr+'c',n,k);
    //         if(!ans.empty()) return ans;
    //     }
    //     return "";
    // }

    // BRUTE
    void helper(vector<string>&ans,string curr,int n){
        if(curr.size()==n){
            ans.push_back(curr);
            return ;
        }
        if(curr.empty() || curr.back()!='a'){
            helper(ans,curr+'a',n);
        }
        if(curr.empty() || curr.back()!='b'){
            helper(ans,curr+'b',n);
        }
        if(curr.empty() || curr.back()!='c'){
            helper(ans,curr+'c',n);
        }
    }
    string getHappyString(int n, int k) {
        //return helper("",n,k);  

        // BRUTE
        vector<string>ans;
        helper(ans,"",n);
        int cnt=1;
        string ANS="";
        for(int i=0;i<ans.size();i++){
            if(cnt==k){
                ANS=ans[i];
                break;
            }
            cnt++;
        }  
        return ANS;   
    }
};