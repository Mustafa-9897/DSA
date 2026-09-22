class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0,j=0;
        string ans="";
        int cnt=0;
        while(i<s.size() && j<spaces.size()){
            if(cnt==spaces[j]){
                ans += " ";
                j++;
            }
            ans += s[i];
            i++;
            cnt++;
        }
        while(i<s.size()){
            ans += s[i];
            i++;
        }
        return ans;
    }
};