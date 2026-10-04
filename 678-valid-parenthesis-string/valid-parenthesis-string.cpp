class Solution {
public:
    bool checkValidString(string s) {
        int min=0,max=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{             // when s[i]=* then min ko minus kar aur minimum banane ke liye and max ko plus kar aur maximum bane ke liye
                min--;
                max++;
            }
            if(min<0){
                min=0;
            }
            if(max<0){        // eg. s=)*()
                return false;
            }
        }
        return min==0;
    }
};