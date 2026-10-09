class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            // if you encounter ( add it to the stack
            if(s[i]=='('){
                st.push('(');
            }
            // if you encounter ) , now do the following
            else{

                // if the next char is also ) means we have a valid closing
                if(i+1<n && s[i+1]==')'){
                    i++;
                }
                // means there is no 2nd ) so we will have to add it so ans++
                else{
                    ans++;
                }

                // if st contains ( so pop it since for this ( we arranged the ) above
                if(!st.empty()) st.pop();
                // if there is no ( means we have to add it so ans++
                else ans++;
            }
        }
        // if there are still ( int he stack then we will need twice as much ) so ans += 2*
        ans += 2*st.size();
        return ans;
    }
};