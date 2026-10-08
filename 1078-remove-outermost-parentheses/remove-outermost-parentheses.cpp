class Solution {
public:
    string removeOuterParentheses(string s) {
        // string ans="";
        // int level=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         if(level>0) ans += '(';  // if the level>0 then it means it is not the outermost parenthesis so add this ( to the ans.
        //         level++; // increase the level as we are entering the new level
        //     }
        //     else if(s[i]==')'){
        //         level--; // ) indicates we have crossed 1 level of parenthesis so decrease the level.
        //         if(level>0) ans += ')'; // level>0 means we are inside and it is not the outermost parenthesis so add it to the answer.
        //     }
        // }
        // return ans;

        vector<string>temp;
        int balance=0;
        string t="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                t += '(';
                balance++;
            }
            else{
                balance--;
                t += ')';
            }
            if(balance==0){
                temp.push_back(t);
                t="";
            }
        }
        string ans="";
        for(int i=0;i<temp.size();i++){
            int j=1;
            string S=temp[i];
            while(j<S.size()-1){
                ans += S[j];
                j++;
            }
        }
        return ans;
    }
};