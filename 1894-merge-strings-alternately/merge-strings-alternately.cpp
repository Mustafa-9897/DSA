class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans="";
        int cnt=0;
        while(i<word1.size() && j<word2.size()){
            if(cnt%2==0){
                ans += word1[i];
                i++;
            }
            else{
                ans += word2[j];
                j++;
            }
            cnt++;
        }
        while(i<word1.size()){
            ans += word1[i];
            i++;
        }
        while(j<word2.size()){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};