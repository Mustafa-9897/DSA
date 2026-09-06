class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int sum=0;
            for(int j=0;j<s.size();j++){
                sum += weights[s[j]-'a'];
            }
            sum = sum % 26;
            ans += char(122-sum); // ascii 'a' -> 'z' == 97 -> 122
        }
        return ans;
    }
};