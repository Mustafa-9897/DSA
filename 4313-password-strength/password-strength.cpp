class Solution {
public:
    int passwordStrength(string password) {
        // Lowercase letters	97–122	a to z
        // Uppercase letters	65–90	A to Z
        // Digits	            48–57	0 to 9

        int ans=0;
        set<int>st;
        for(int i=0;i<password.size();i++){
            st.insert(password[i]);
        }
        for(auto it:st){
            char ch=it;
            if(ch>='a' && ch<='z') ans += 1;
            else if(ch>='A' && ch<='Z') ans += 2;
            else if(ch>='0' && ch<='9') ans += 3;
            else ans += 5;
        }
        return ans;
    }
};