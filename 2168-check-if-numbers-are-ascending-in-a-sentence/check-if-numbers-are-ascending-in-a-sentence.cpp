class Solution {
public:
    bool areNumbersAscending(string s) {
        int n=s.size();
        int lastmin=-1;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int num=0;
                while(i<n && isdigit(s[i])){
                    num=num*10+s[i]-'0';
                    i++;
                }
                if(num<=lastmin){
                    return false;
                }
                lastmin=num;
            }
        }
        return true;
    }
};