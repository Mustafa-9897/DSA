class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26);  // maintains the last occurences of all s[i]
        vector<bool>visited(26,false); //keeps the track of which characters are in the stack
        stack<char>st;
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(visited[ch-'a']){  // if the char is already in the stack then if s[i]==char
                continue;         // then continue beacuse hame answer me sirf unique chahiye
            }

            while(!st.empty() && ch<st.top() && last[st.top()-'a']>i){
                visited[st.top()-'a']=false; // since char pop hora so uska visited will
                st.pop();                    // become false
            }
            st.push(ch);
            visited[ch-'a']=true;
        }
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};