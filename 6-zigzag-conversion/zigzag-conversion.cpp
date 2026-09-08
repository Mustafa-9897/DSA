class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()){
            return s;
        }
        vector<string>rows(numRows);
        int direction =1 ; // 1 means down , -1  means up(so we can go backwards in string )
        int row=0;
        for(char c : s){
            rows[row] += c;
            if(row==0){
                direction=1;
            }
            if(row==numRows-1){
                direction=-1;
            }
            row += direction ;
        }
        string ans="";
        for(string &S :rows){
            ans += S;
        }
        return ans;
    }
};