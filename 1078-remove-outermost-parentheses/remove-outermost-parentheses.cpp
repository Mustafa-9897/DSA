class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int level=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(level>0) ans += '(';  // if the level>0 then it means it is not the outermost parenthesis so add this ( to the ans.
                level++; // increase the level as we are entering the new level
            }
            else if(s[i]==')'){
                level--; // ) indicates we have crossed 1 level of parenthesis so decrease the level.
                if(level>0) ans += ')'; // level>0 means we are inside and it is not the outermost parenthesis so add it to the answer.
            }
        }
        return ans;
    }
};