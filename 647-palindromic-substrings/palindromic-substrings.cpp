class Solution {
public:
    int countSubstrings(string s) {
        //    BRUTE
        // int ans=0;
        // for(int i=0;i<s.size();i++){
        //     string t="";
        //     for(int j=i;j<s.size();j++){
        //         t += s[j];
        //         int l=0,r=t.size()-1;
        //         int flag=1;
        //         while(l<r){
        //             if(t[l]!=t[r]){
        //                 flag=0;
        //             }
        //             l++;
        //             r--;
        //         }
        //         if(flag==1) ans++;
        //     }
        // }
        // return ans;

        // OPTIMAL
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            // odd length string
            int l=i,r=i;
            while(l>=0 && r<n &&s[l]==s[r]){
                ans++;
                l--;r++;
            }
            // even length string
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                l--;r++;
            }
        }
        return ans;
    }
};