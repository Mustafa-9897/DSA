class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            string t="";
            for(int j=i;j<s.size();j++){
                t += s[j];
                int l=0,r=t.size()-1;
                int flag=1;
                while(l<r){
                    if(t[l]!=t[r]){
                        flag=0;
                    }
                    l++;
                    r--;
                }
                if(flag==1) ans++;
            }
        }
        return ans;
    }
};