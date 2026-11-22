class Solution {
public:
    bool checkString(string s) {
        if(s.size()==1) return true;
        int ai=-1,bi=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                ai=i;
            }
            else{
                if(bi==-1){
                    bi=i;
                }
            }
        }
        if(ai>bi && bi!=-1) return false;
        return true;
    }
};