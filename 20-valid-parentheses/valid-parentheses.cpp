class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            char ch=s[i];
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char c=st.top();
                st.pop();
                if((c=='(' && ch==')') ||(c=='[' && ch==']') || (c=='{' && ch=='}') ){
                    
                }
                else{
                    return false;
                }
            }
            i++;
        }
        return st.empty();
    }
};