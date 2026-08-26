class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<int>st;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])!=0){
                return s[i];
            }
            st.insert(s[i]);
        }
        return 'a';
    }
};